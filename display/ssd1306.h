#ifndef DISPLAY_SSD1306_H
#define DISPLAY_SSD1306_H

struct Glyph {
  int32_t skip : 7;
  int32_t xoffset : 7;
  int32_t yoffset : 7;
  int32_t columns : 8;
  int32_t column_size : 3;
  const void* data;
};

const uint32_t BatteryBar16_data[] = {
   0b00000000000000000000000000000000UL,
   0b00000111111111111111111111100000UL,
   0b00011111111111111111111111111000UL,
   0b00111111111111111111111111111100UL,
   0b01111111111111111111111111111110UL,
   0b11111111111111111111111111111111UL,
   0b11111111111111111111111111111111UL,
   0b11111111111111111111111111111111UL,
   0b11111111111111111111111111111111UL,
   0b11111111111111111111111111111111UL,
   0b11111111111111111111111111111111UL,
   0b01111111111111111111111111111110UL,
   0b00111111111111111111111111111100UL,
   0b00011111111111111111111111111000UL,
   0b00000111111111111111111111100000UL,
};

#define GLYPHDATA(X) NELEM(X), sizeof((X)[0]) - 1, (const void*)X

const Glyph BatteryBar16 = { 16, 0, 0, GLYPHDATA(BatteryBar16_data) };

#include "StarJedi10Font.h"

class SSD1306 : public I2CDevice, Looper, StateMachine, SaberBase, private AudioStreamWork {
public:
  static const int WIDTH = 128;
  static const int HEIGHT = 32;
  const char* name() override { return "SSD1306"; }

  enum Commands {
    SETCONTRAST = 0x81,
    DISPLAYALLON_RESUME = 0xA4,
    DISPLAYALLON = 0xA5,
    NORMALDISPLAY = 0xA6,
    INVERTDISPLAY = 0xA7,
    DISPLAYOFF = 0xAE,
    DISPLAYON = 0xAF,

    SETDISPLAYOFFSET = 0xD3,
    SETCOMPINS = 0xDA,

    SETVCOMDETECT = 0xDB,

    SETDISPLAYCLOCKDIV = 0xD5,
    SETPRECHARGE = 0xD9,

    SETMULTIPLEX = 0xA8,

    SETLOWCOLUMN = 0x00,
    SETHIGHCOLUMN = 0x10,

    SETSTARTLINE = 0x40,

    MEMORYMODE = 0x20,
    COLUMNADDR = 0x21,
    PAGEADDR   = 0x22,

    COMSCANINC = 0xC0,
    COMSCANDEC = 0xC8,

    SEGREMAP = 0xA0,

    CHARGEPUMP = 0x8D,

    EXTERNALVCC = 0x1,
    SWITCHCAPVCC = 0x2,

    // Scrolling commands
    ACTIVATE_SCROLL = 0x2F,
    DEACTIVATE_SCROLL = 0x2E,
    SET_VERTICAL_SCROLL_AREA = 0xA3,
    RIGHT_HORIZONTAL_SCROLL = 0x26,
    LEFT_HORIZONTAL_SCROLL = 0x27,
    VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL = 0x29,
    VERTICAL_AND_LEFT_HORIZONTAL_SCROLL = 0x2A,
  };

  enum Screen {
    SCREEN_STARTUP,
    SCREEN_MESSAGE,
    SCREEN_PLI,
    SCREEN_IMAGE,  // also for animations
  };

  enum ScreenLayout {
    LAYOUT_NATIVE,
    LAYOUT_LANDSCAPE,
    LAYOUT_PORTRAIT,
  };

  SSD1306() : I2CDevice(0x3C) { }
  void Send(int c) { writeByte(0, c); }

  template<typename T>
  void Draw2(int begin, int end, uint32_t* pos, int shift, const T* data) {
    if (shift > 0) {
      for (int i = begin; i < end; i++) pos[i] |= data[i] << shift;
    } else if (shift < 0) {
      for (int i = begin; i < end; i++) pos[i] |= data[i] >> -shift;
    } else {
      for (int i = begin; i < end; i++) pos[i] |= data[i];
    }
  }

  void Draw(const Glyph& glyph, int x, int y) {
    x += glyph.xoffset;
    y += glyph.yoffset;
    int begin = std::max<int>(0, -x);
    int end = std::min<int>(glyph.columns, WIDTH - x);
    uint32_t *pos = frame_buffer_ + x;
    switch (glyph.column_size) {
      case 0:
	Draw2<uint8_t>(begin, end, pos, y, (const uint8_t*)glyph.data);
	break;
      case 1:
	Draw2<uint16_t>(begin, end, pos, y, (const uint16_t*)glyph.data);
	break;
      case 3:
	Draw2<uint32_t>(begin, end, pos, y, (const uint32_t*)glyph.data);
	break;
    }
  }

  void DrawBatteryBar(const Glyph& bar) {
    int start, end;
    if (bar.skip < bar.columns) {
      start = -bar.skip;
      end = WIDTH + bar.columns - 1;
    } else {
      start = 0;
      end = WIDTH;
    }
    int max_bars = (end - start) / bar.skip;
    int pos = start;
    int bars = floorf(
        battery_monitor.battery_percent() * (0.5 + max_bars) / 100);
    for (int i = 0; i < bars; i++) {
      Draw(bar, pos, 0);
      pos += bar.skip;
    }
  }
  void DrawText(const char* str,
                int x, int y,
                const Glyph* font) {
    while (*str) {
      if (*str == '\n') {
        x = 0;
        y += 16;
      } else if (*str >= 0x20 && *str <= 0x7f) {
        Draw(font[*str - 0x20], x, y);
        x += font[*str - 0x20].skip;
      }
      str++;
    }
  }

#define FRAME_RATE_SLEEP 20  

  // Fill frame buffer and return how long to display it.
  int FillFrameBuffer() {
    switch (screen_) {
      case SCREEN_STARTUP:
	memset(frame_buffer_, 0, sizeof(frame_buffer_));
        DrawText("==SabeR===", 0,15, Starjedi10pt7bGlyphs);
        DrawText("++Teensy++",-4,31, Starjedi10pt7bGlyphs);
	screen_ = SCREEN_PLI;
	layout_ = LAYOUT_NATIVE;
	xor_ = 0;
	return 5000;

      case SCREEN_PLI:
	memset(frame_buffer_, 0, sizeof(frame_buffer_));
        DrawBatteryBar(BatteryBar16);
	layout_ = LAYOUT_NATIVE;
	xor_ = 0;
	return 200;  // redraw once every 200 ms

      case SCREEN_MESSAGE:
	memset(frame_buffer_, 0, sizeof(frame_buffer_));
        if (strchr(message_, '\n')) {
          DrawText(message_, 0, 15, Starjedi10pt7bGlyphs);
        } else {
          DrawText(message_, 0, 23, Starjedi10pt7bGlyphs);
        }
	screen_ = SCREEN_PLI;
	layout_ = LAYOUT_NATIVE;
	xor_ = 0;
	return 5000;

      case SCREEN_IMAGE:
	MountSDCard();
	if (!frame_available_) {
	  scheduleFillBuffer();
	  return 1;
	}
	if (eof_) {
	  screen_ = SCREEN_PLI;
	  if (frame_count_ == 1) return 5000;
	  return FillFrameBuffer();
	}
	frame_count_++;
	if (looped_ && millis() - loop_start_ > 5000)
	  screen_ = SCREEN_PLI;
	// Screen updates takes enough time
	// that no sleeping is really needed.
	return FRAME_RATE_SLEEP;
    }
  }

  void SetScreenNow(Screen screen) {
    millis_to_display_ = 0;
    // This aborts the sleep in the display loop.
    state_machine_.sleep_until_ = millis();
    screen_ = screen;
  }

  void ShowFile(Effect* effect) {
    MountSDCard();
    file_.Play(effect);
    loop_start_ = millis();
    frame_count_ = 0;
    SetScreenNow(SCREEN_IMAGE);
    eof_ = false;
  }

  void ShowFile(const char* file) {
    MountSDCard();
    file_.Play(file);
    loop_start_ = millis();
    frame_count_ = 0;
    SetScreenNow(SCREEN_IMAGE);
    scheduleFillBuffer();
    eof_ = false;
  }

  void SB_NewFont() override {
    if (logo.files_found()) {
      // Overrides message from below..
      ShowFile(&logo);
    }
  }

  void SB_Message(const char* text) override {
    strncpy(message_, text, sizeof(message_));
    message_[sizeof(message_)-1] = 0;
    SetScreenNow(SCREEN_MESSAGE);
  }

  void SB_Top() override {
    STDOUT.print("display fps: ");
    loop_counter_.Print();
    STDOUT.println("");
  }

  void Loop() override {
    STATE_MACHINE_BEGIN();
    while (!i2cbus.inited()) YIELD();

    // Init sequence
    Send(DISPLAYOFF);                    // 0xAE
    Send(SETDISPLAYCLOCKDIV);            // 0xD5
    Send(0x80);                                  // the suggested ratio 0x80
    
    Send(SETMULTIPLEX);                  // 0xA8
    Send(HEIGHT - 1);
    
    Send(SETDISPLAYOFFSET);              // 0xD3
    Send(0x0);                                   // no offset
    Send(SETSTARTLINE | 0x0);            // line #0
    Send(CHARGEPUMP);                    // 0x8D
    Send(0x14);
    Send(MEMORYMODE);                    // 0x20
    Send(0x01);                          // vertical address mode
    Send(SEGREMAP | 0x1);
    Send(COMSCANDEC);

    Send(SETCOMPINS);                    // 0xDA
    Send(0x02);  // may need to be 0x12 for some displays
    Send(SETCONTRAST);                   // 0x81
    Send(0x8F);

    Send(SETPRECHARGE);                  // 0xd9
    Send(0xF1);
    Send(SETVCOMDETECT);                 // 0xDB
    Send(0x40);
    Send(DISPLAYALLON_RESUME);           // 0xA4
    Send(NORMALDISPLAY);                 // 0xA6
    
    Send(DEACTIVATE_SCROLL);

    Send(DISPLAYON);                     //--turn on oled panel

    STDOUT.println("Display initialized.");
    screen_ = SCREEN_STARTUP;
    
    while (true) {
      millis_to_display_ = FillFrameBuffer();
      
      Send(COLUMNADDR);
      Send(0);   // Column start address (0 = reset)
      Send(WIDTH-1); // Column end address (127 = reset)

      Send(PAGEADDR);
      Send(0); // Page start address (0 = reset)
      switch (HEIGHT) {
        case 64:
          Send(7); // Page end address
          break;
        case 32:
          Send(3); // Page end address
          break;
        case 16:
          Send(1); // Page end address
          break;
        default:
          STDOUT.println("Unknown display height");
      }

      //STDOUT.println(TWSR & 0x3, DEC);
        
      // I2C
      for (i=0; i < WIDTH * HEIGHT / 8; ) {
        // send a bunch of data in one xmission
        Wire.beginTransmission(address_);
        Wire.write(0x40);
        for (uint8_t x=0; x<16; x++) {
	  uint8_t b;
	  switch (layout_) {
	    case LAYOUT_NATIVE:
	      b = ((unsigned char *)frame_buffer_)[i];
	      break;
	    case LAYOUT_PORTRAIT:
	      b = ~((unsigned char *)frame_buffer_)[i ^ 3];
	      break;
	    case LAYOUT_LANDSCAPE: {
	      int x = i >> 2;
	      int y = ((i & 3) << 3) + 7;
//	      STDOUT << " LANDSCAPE DECODE!! x = " << x << " y = " << y << "\n";
	      
	      int shift = 7 - (x & 7);
	      uint8_t *pos =
		((unsigned char*)frame_buffer_) + ((x>>3) + (y<<4));
	      b = 0;
	      for (int j = 0; j < 8; j++) {
		b <<= 1;
		b |= (*pos >> shift) & 1;
		pos -= 16;
	      }
	    }
	  }
	  Wire.write(b ^ xor_);
          i++;
        }
        Wire.endTransmission();
	I2CUnlock(); do { YIELD(); } while (!I2CLock());

	// Slightly incorrect since it doesn't accunt for
	// the time it takes to actually show the image.
      }
      loop_counter_.Update();
      frame_available_ = false;
      scheduleFillBuffer();
      SLEEP(millis_to_display_);
    }
    
    STATE_MACHINE_END();
  }

#define TAG2(X, Y) (((X) << 8) | (Y))

  bool ReadImage(FileReader* f) {
    uint32_t file_end = 0;
    if (ypos_ >= height_) {
      if (looped_) f->Seek(0);
      ypos_ = 0;
      uint32_t file_start = f->Tell();
      int a = f->Read();
      int b = f->Read();
      int width;
      switch (TAG2(a, b)) {
	default:
	  STDOUT << "Unknown image format.\n";
	  return false;
	  
	case TAG2('P', '4'):
	  // PBM
	  f->skipwhite();
	  width = f->readIntValue();
	  f->skipwhite();
	  height_ = f->readIntValue();
	  f->Read();
	  xor_ = 255;
	  break;
	  
	case TAG2('B', 'M'):
	case TAG2('B', 'A'):
	case TAG2('C', 'I'):
	case TAG2('C', 'P'):
	case TAG2('I', 'C'):
	case TAG2('P', 'T'):
	  xor_ = 0;
	  // BMP
	  file_end = file_start + f->ReadType<uint32_t>();
	  STDOUT << "BMP detected!\n";
	  f->Skip(4);
	  uint32_t offset = f->ReadType<uint32_t>();
	  f->Skip(4);
	  width = f->ReadType<uint16_t>();
	  height_ = f->ReadType<uint16_t>();
	  f->Seek(file_start + offset);
      }
      if (width != 128 && width != 32) {
	STDOUT << "Wrong size image: " << width << "x" << height_ << "\n";
	return false;
      }
      if (width == 128) {
	layout_ = LAYOUT_LANDSCAPE;
	looped_ = height_ > 32;
      } else {
	looped_ = height_ > 128;
      }
    }
    if (f->Available() < sizeof(frame_buffer_)) return false;
    f->Read((uint8_t*)frame_buffer_, sizeof(frame_buffer_));
    ypos_ += 32;
    if (file_end) f->Seek(file_end);
    return true;
  }

  // AudioStreamWork implementation
  size_t space_available() const override {
    if (eof_) return 0;
    if (frame_available_) return 0;

    // Always low priority
    return 1;
  }

  bool FillBuffer() override {
    if (eof_) return true;
    if (!file_.IsOpen()) {
      if (!file_.OpenFile()) {
	eof_ = true;
      }
      ypos_ = height_;
      return false;
    }
    if (!frame_available_) {
      if (!ReadImage(&file_)) {
	file_.Close();
	eof_ = true;
      }
      frame_available_ = true;
    }
    return true;
  }
  void CloseFiles() override {
    file_.Close();
  }

  // TODO: Don't update the display when we don't need to
  // and return false here so that we can go into lower power modes.
  void SB_IsOn(bool* on) override {
    *on = true;
  }
private:
  uint16_t i;
  uint8_t xor_ = 0;
  uint32_t frame_buffer_[WIDTH];
  LoopCounter loop_counter_;
  char message_[32];
  uint32_t millis_to_display_;
  Screen screen_;
  int32_t height_ = 0;
  int32_t ypos_ = 0;
  volatile ScreenLayout layout_;
  uint32_t loop_start_;
  uint32_t frame_count_ = 0;

  EffectFileReader file_;
  volatile bool frame_available_ = true;
  volatile bool eof_ = true;
  volatile bool looped_ = false;
};

#endif

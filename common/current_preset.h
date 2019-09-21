#ifndef COMMON_CURRENT_PRESET_H
#define COMMON_CURRENT_PRESET_H

#include "preset.h"
#include "file_reader.h"
#include "blade_config.h"

class CurrentPreset {
public:
  enum { PRESET_DISK, PRESET_ROM } preset_type;
  int preset_num;
  int color_seq = 0;
  int effect_seq= 0;
  int color_scroll_seq = 0;
  int color_fade_seq = 0;
  LSPtr<char> font;
  LSPtr<char> track;
#define DEFINE_CURRENT_STYLE_STRING(N) LSPtr<char> current_style##N;
  ONCEPERBLADE(DEFINE_CURRENT_STYLE_STRING);
  LSPtr<char> name;

  const char *mk_builtin_str(int num, int N) {
    char tmp[30];
    strcpy(tmp, "builtin ");
    itoa(num, tmp + strlen(tmp), 10);
    strcat(tmp, " ");
    itoa(N, tmp + strlen(tmp), 10);
    char *ret = (char *)malloc(strlen(tmp)+1);
    if (!ret) return "";
//    STDOUT.print("MALLOC ");
//    STDOUT.println((uint32_t)ret, HEX);
    strcpy(ret, tmp);
    return ret;
  }

  void Clear() {
    font = "";
    track = "";
#define CLEAR_STYLE_STRING(N) current_style##N = "";
    ONCEPERBLADE(CLEAR_STYLE_STRING);
    name = "";
    color_seq = -1;
    effect_seq = -1;
    color_scroll_seq = -1;
    color_fade_seq = -1;
  }

  void Set(int num) {
    num = (current_config->num_presets + num) % current_config->num_presets;
    Preset* preset = current_config->presets + num;
    preset_type = PRESET_ROM;
    preset_num = num;
    color_seq = 0;
    effect_seq = 0;
    color_scroll_seq = 0;
    color_fade_seq = 0;
    font = preset->font;
    track = preset->track;
#define MAKE_STYLE_STRING(N) current_style##N = mk_builtin_str(num, N);
    ONCEPERBLADE(MAKE_STYLE_STRING);
    name = preset->name;
  }

  bool Read(FileReader* f) {
    int preset_count = 0;
    int current_style = 0;
    if (f->Tell() == 0) preset_num = -1;
    preset_type = PRESET_DISK;

    for (; f->Available(); f->skipline()) {
      char variable[33];
      f->skipwhite();
      if (f->Peek() == '#') continue;
      int line_begin = f->Tell();
      f->readVariable(variable);
      if (!variable[0]) continue;
      if (!strcmp(variable, "new_preset")) {
	preset_count++;
	if (preset_count == 2) {
	  preset_num++;
	  // Go back to the beginning of the line
	  f->Seek(line_begin);
	  return true;
	}
	continue;
      }
      if (!preset_count) return false;
      if (f->Peek() != '=') continue;
      f->Read();
      f->skipwhite();

      if (!strcmp(variable, "end")) {
	f->Seek(line_begin);
	if (preset_count == 1) {
	  preset_num++;
	  return true;
	}
	return false;
      }

      if (!strcmp(variable, "name")) {
	name = f->readString();
	continue;
      }
      if (!strcmp(variable, "font")) {
	font = f->readString();
	continue;
      }
      if (!strcmp(variable, "track")) {
	track = f->readString();
	continue;
      }
      if (!strcmp(variable, "color_seq")) {
        color_seq = f->readIntValue();
        continue;
      }
      if (!strcmp(variable, "effect_seq")) {
        effect_seq = f->readIntValue();
        continue;
      }
      if (!strcmp(variable, "color_scroll_seq")) {
        color_scroll_seq = f->readIntValue();
        continue;
      }
      if (!strcmp(variable, "color_fade_seq")) {
        color_fade_seq = f->readIntValue();
        continue;
      }
      if (!strcmp(variable, "style")) {
	current_style++;
	char* tmp = f->readString();
#define SET_PRESET_STYLE(N) if (current_style == N) { current_style##N = tmp; tmp = 0; }
	ONCEPERBLADE(SET_PRESET_STYLE);
	if (tmp) free(tmp);
      }
    }
    if (preset_count == 1) {
      preset_num++;
      return true;
    }
    return false;
  }

  bool Write(FileReader* f) {
    f->Write("new_preset\n");
    f->write_key_value("font", font.get());
    f->write_key_value("track", track.get());
    char value[30];
    itoa(color_seq, value, 10);
    f->write_key_value("color_seq", value);
    itoa(effect_seq, value, 10);
    f->write_key_value("effect_seq", value);
    itoa(color_scroll_seq, value, 10);
    f->write_key_value("color_scroll_seq", value);
    itoa(color_fade_seq, value, 10);
    f->write_key_value("color_fade_seq", value);
#define WRITE_PRESET_STYLE(N) f->write_key_value("style", current_style##N.get());
    ONCEPERBLADE(WRITE_PRESET_STYLE);
    f->write_key_value("name", name.get());
    return true;
  }

  void Print() {
    PrintQuotedValue("FONT", font.get());
    PrintQuotedValue("TRACK", track.get());
    char value[30];
    itoa(color_seq, value, 10);
    PrintQuotedValue("COLOR_SEQ", value);
    itoa(effect_seq, value, 10);
    PrintQuotedValue("EFFECT_SEQ", value);
    itoa(color_scroll_seq, value, 10);
    PrintQuotedValue("COLOR_SCROLL_SEQ", value);
    itoa(color_fade_seq, value, 10);
    PrintQuotedValue("COLOR_FADE_SEQ", value);
#define PRINT_PRESET_STYLE(N) PrintQuotedValue("STYLE" #N, current_style##N.get());
    ONCEPERBLADE(PRINT_PRESET_STYLE);
    PrintQuotedValue("NAME", name.get());
  }

  static bool isSpace(int c) {
    return c == '\n' || c == '\r' || c == ' ' || c == '\t';
  }

  bool OpenPresets(FileReader* f, const char* filename) {
    if (!f->Open(filename))
      return false;

    if (f->FileSize() < 4) return false;
    int p = f->FileSize() - 1;
    while (p > 0) { f->Seek(p); if (!isSpace(f->Read())) break; p--; }
    f->Seek(p - 3);
    if (!isSpace(f->Read())) return false;
    if (toLower(f->Read()) != 'e') return false;
    if (toLower(f->Read()) != 'n') return false;
    if (toLower(f->Read()) != 'd') return false;
    f->Seek(0);

    return true;
  }

  bool UpdateINI() {
    FileReader f, f2;
    if (OpenPresets(&f2, "presets.tmp")) {
      uint8_t buf[512];
      // Found valid tmp file
      LSFS::Remove("presets.ini");
      f.Create("presets.ini");
      while (f2.Available()) {
	int to_copy = std::min<int>(f2.Available(), sizeof(buf));
	if (f2.Read(buf, to_copy) != to_copy ||
	    f.Write(buf, to_copy) != to_copy) {
	  f2.Close();
	  f.Close();
	  LSFS::Remove("presets.ini");
	  return false;
	}
      }
      f2.Close();
      f.Close();
      return true;
    }
    return false;
  }

  bool CreateINI() {
    FileReader f;
    f.Create("presets.ini");
    CurrentPreset tmp;
    for (size_t i = 0; i < current_config->num_presets; i++) {
      tmp.Set(i);
      tmp.Write(&f);
    }
    f.Write("end\n");
    f.Close();
    return true;
  }

  // preset = -1 means to load the *last* pre
  bool Load(int preset) {
    FileReader f;
    if (!OpenPresets(&f, "presets.ini")) {
      if (!UpdateINI()) return false;
      if (!OpenPresets(&f, "presets.ini")) return false;
    }

    int n = 0;
    while (true) {
      if (Read(&f)) {
	if (n == preset) return true;
	n++;
      } else {
	if (n && preset == -1) return true;
	if (n == preset) {
	  f.Seek(0);
	  n=0;
	  Read(&f);
	  return true;
	}
	return false;
      }
    }
  }

  // position = 0 -> first spot
  // position = N -> last
  // position = -1 -> delete
  // To duplicate, set preset_num to -1
  void SaveAt(int position) {
    LOCK_SD(true);
    FileReader f, out;
    if (!OpenPresets(&f, "presets.ini")) {
      if (!UpdateINI()) CreateINI();
      OpenPresets(&f, "presets.ini");
    }
    LSFS::Remove("presets.tmp");
    out.Create("presets.tmp");
    CurrentPreset tmp;
    int opos = 0;
    if (position == 0) {
      Write(&out);
      opos++;
    }
    while (tmp.Read(&f)) {
      if (tmp.preset_num != preset_num) {
	tmp.Write(&out);
	opos++;
	if (position == opos) {
	  Write(&out);
	  opos++;
	}
      }
    }
    f.Close();
    out.Write("end\n");
    out.Close();
    UpdateINI();
    preset_num = position;
    LOCK_SD(false);
  }

  void Save() { SaveAt(preset_num); }

  void ClearPresets() {
    SaberBase::DoSetColor(0);
    SaberBase::DoSetEffect(0);
    SaberBase::DoSetColorFade(0);
    SaberBase::DoSetColorScroll(0);
    LOCK_SD(true);
    LSFS::Remove("presets.ini");
    LSFS::Remove("presets.tmp");
    LSFS::Remove("savedpreset.ini");
    dynamic_mixer.set_volume(VOLUME);
    LOCK_SD(false);
  }

  void SetPreset(int preset) {
    //Clear();
    #ifdef SAVED_PRESET
    if (font.get() != NULL) {
      Save();
      SavePreset(preset);
    }
    Clear();
    LOCK_SD(true);
    if (!Load(preset)) {
      Set(preset);
    }
    LOCK_SD(false);
    #else
    Set(preset);
    #endif
  }

bool SavePreset(int preset) {
  if (preset >= 0 && preset <= current_config->num_presets) {
    LOCK_SD(true);
    FileReader c;
    LSFS::Remove("savedpreset.ini");
    c.Create("savedpreset.ini");
    char value[30];
    itoa(preset, value, 10);
    c.write_key_value("preset", value);
    itoa(dynamic_mixer.get_volume(), value, 10);
    c.write_key_value("volume", value);
    c.Close();
    LOCK_SD(false);
  }
}
};

#endif

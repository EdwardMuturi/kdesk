/**
 * config.h
 *
 * Copyright (C) 2013-2018 Kano Computing Ltd.
 * License: http://www.gnu.org/licenses/gpl-2.0.txt GNU GPLv2
 *
 * An app to show and bring life to Kano-Make Desktop Icons.
 *
 */


#ifndef __KDESK_CONFIGURATION_H__
#define __KDESK_CONFIGURATION_H__


#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#define MAX_ICONS 64
#define CACHE_DIRECTORY_ICONS ".cache/kdesk/icons"
#define SVG_PNG_CONVERTER     "rsvg-convert"

class Configuration
{
 protected:
  std::ifstream ifile;
  std::map <std::string, std::string> configuration;
  std::map<int,std::map<std::string,std::string> > icons;
  int numicons;
  Configuration *pconf;

 public:
  Configuration ();
  virtual ~Configuration (void);
  bool load_conf (const char *filename);
  bool load_icons (const char *directory);
  bool parse_icon (const char *directory, std::string fname, int iconid);
  std::string convert_svg(std::string icon_filename);
  std::string localize_icon(std::string icon_filename);
  void dump (void);
  void reset(void);
  void reset_icons(void);
  std::string get_spaced_value(void);

  std::string get_config_string(std::string item);
  unsigned int get_config_int(std::string item);
  std::string get_icon_string(int iconid, std::string key);
  int get_icon_int(int iconid, std::string key);
  int get_numicons(void);
};


#endif  // __KDESK_CONFIGURATION_H__

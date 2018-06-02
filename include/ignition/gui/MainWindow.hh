/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_GUI_MAINWINDOW_HH_
#define IGNITION_GUI_MAINWINDOW_HH_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "ignition/gui/qt.h"
#include "ignition/gui/Export.hh"

namespace ignition
{
  namespace gui
  {
    class MainWindowPrivate;
    struct WindowConfig;

    class IGNITION_GUI_VISIBLE MainWindow : public QObject
    {
      Q_OBJECT

      /// \brief Constructor
      public: MainWindow();

      /// \brief Destructor
      public: virtual ~MainWindow();

//      /// \brief Close all docks
//      /// \return True if all docks have been closed
//      public: bool CloseAllDocks();
//
//      /// \brief Save current window and plugin configuration to a file on disk.
//      /// Will open an error dialog in case it's not possible to write to the
//      /// path.
//      /// \param[in] _path The full destination path including filename.
//      public: void SaveConfig(const std::string &_path);
//
//      /// \brief Apply a WindowConfig to this window and keep a copy of it.
//      /// \param[in] _config The configuration to apply.
//      /// \return True if successful.
//      public: bool ApplyConfig(const WindowConfig &_config);
//
//      // Documentation inherited
//      protected: void paintEvent(QPaintEvent *_event) override;
//
//      // Documentation inherited
//      protected: void closeEvent(QCloseEvent *_event) override;
//
//      /// \brief Get the current window configuration.
//      /// \return Updated window config
//      private: WindowConfig CurrentWindowConfig() const;
//
//      /// \brief Callback when load configuration is selected
//      private slots: void OnLoadConfig();
//
//      /// \brief Callback when "save configuration" is selected
//      private slots: void OnSaveConfig();
//
//      /// \brief Callback when "save configuration as" is selected
//      private slots: void OnSaveConfigAs();
//
//      /// \brief Callback when load stylesheet is selected
//      private slots: void OnLoadStylesheet();

      /// \brief Add a plugin to the window.
      /// \param [in] _plugin Plugin filename
      public slots: void OnAddPlugin(QString _plugin);

      /// \internal
      /// \brief Private data pointer
      private: std::unique_ptr<MainWindowPrivate> dataPtr;
    };

    /// \brief Holds configurations related to a MainWindow.
    struct IGNITION_GUI_VISIBLE WindowConfig
    {
      /// \brief Update this config from an XML string. Only fields present on
      /// the XML will be overriden / created.
      /// \param[in] _xml A config XML file in string format
      /// \return True if successful. It may fail for example if the string
      /// can't be parsed into XML.
      bool MergeFromXML(const std::string &_xml);

      /// \brief Return this configuration in XML format as a string.
      /// \return String containing a complete config file.
      std::string XMLString() const;

      /// \brief Window X position in px
      int posX{-1};

      /// \brief Window Y position in px
      int posY{-1};

      /// \brief Window width in px
      int width{-1};

      /// \brief Window height in px
      int height{-1};

      /// \brief Window state (dock configuration)
      QByteArray state;

      /// \brief String holding the global style sheet in QSS format.
      std::string styleSheet{""};

      /// \brief Map menu name to whether it should be visible, all menus are
      /// shown by default.
      std::map<std::string, bool> menuVisibilityMap;

      /// \brief True if plugins found in plugin paths should be listed under
      /// the Plugins menu. True by default.
      bool pluginsFromPaths{true};

      /// \brief List of plugins which should be shown on the list
      std::vector<std::string> showPlugins;

      /// \brief Concatenation of all plugin configurations.
      std::string plugins{""};
    };
  }
}
#endif

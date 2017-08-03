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

#include <gtest/gtest.h>

#include "ignition/gui/Iface.hh"
#include "ignition/gui/MainWindow.hh"

using namespace ignition;
using namespace gui;

/////////////////////////////////////////////////
TEST(MainWindowTest, Constructor)
{
  EXPECT_TRUE(initApp());

  // Constructor
  auto mainWindow = new MainWindow;
  EXPECT_TRUE(mainWindow);

  // Menu
  auto menus = mainWindow->menuBar()->findChildren<QMenu*>();
  EXPECT_EQ(menus[0]->title(), QString("&File"));
  EXPECT_EQ(menus[1]->title(), QString("&Plugins"));

  delete mainWindow;
  EXPECT_TRUE(stop());
}

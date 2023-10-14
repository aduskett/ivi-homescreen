/*
 * Copyright 2020-2023 Toyota Connected North America
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "platform_channel.h"

#ifdef ENABLE_PLUGIN_ACCESSIBILITY
#include "static_plugins/accessibility/accessibility.h"
#endif
#ifdef ENABLE_PLUGIN_ISOLATE
#include "static_plugins/isolate/isolate.h"
#endif
#ifdef ENABLE_PLUGIN_RESTORATION
#include "static_plugins/restoration/restoration.h"
#endif
#ifdef ENABLE_PLUGIN_MOUSE_CURSOR
#include "static_plugins/mouse_cursor/mouse_cursor.h"
#endif
#ifdef ENABLE_PLUGIN_GSTREAMER_EGL
#include "static_plugins/gstreamer_egl/gstreamer_egl.h"
#endif
#ifdef ENABLE_PLUGIN_NAVIGATION
#include "static_plugins/navigation/navigation.h"
#endif
#ifdef ENABLE_PLUGIN_COMP_SURF
#include "static_plugins/comp_surf/comp_surf.h"
#endif
#ifdef ENABLE_PLUGIN_COMP_REGION
#include "static_plugins/comp_region/comp_region.h"
#endif
#ifdef ENABLE_PLUGIN_OPENGL_TEXTURE
#include "static_plugins/opengl_texture/opengl_texture.h"
#endif
#ifdef ENABLE_PLUGIN_PACKAGE_INFO
#include "static_plugins/package_info/package_info.h"
#endif
#ifdef ENABLE_PLUGIN_PLATFORM
#include "static_plugins/platform/platform.h"
#endif
#ifdef ENABLE_PLUGIN_PLATFORM_VIEWS
#include "static_plugins/platform_views/platform_views.h"
#endif
#ifdef ENABLE_PLUGIN_DESKTOP_WINDOW
#include "static_plugins/desktop_window/desktop_window.h"
#endif
#ifdef ENABLE_PLUGIN_TEXT_INPUT
#include "static_plugins/text_input/text_input.h"
#endif
#ifdef ENABLE_PLUGIN_URL_LAUNCHER
#include "static_plugins/url_launcher/url_launcher.h"
#endif
#ifdef ENABLE_PLUGIN_SECURE_STORAGE
#include "static_plugins/secure_storage/secure_storage.h"
#endif
#ifdef ENABLE_PLUGIN_INTEGRATION_TEST
#include "static_plugins/integration_test/integration_test.h"
#endif
#ifdef ENABLE_PLUGIN_LOGGING
#include "static_plugins/logging/logging.h"
#endif
#ifdef ENABLE_PLUGIN_KEYBOARD_MANAGER
#include "static_plugins/keyboard_manager/keyboard_manager.h"
#endif
#ifdef ENABLE_PLUGIN_GOOGLE_SIGN_IN
#include "static_plugins/google_sign_in/google_sign_in.h"
#endif

PlatformChannel* PlatformChannel::singleton = nullptr;

PlatformChannel::PlatformChannel() {
#ifdef ENABLE_PLUGIN_ACCESSIBILITY
  RegisterCallback(Accessibility::kChannelName,
                   &Accessibility::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_ISOLATE
  RegisterCallback(Isolate::kChannelName, &Isolate::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_RESTORATION
  RegisterCallback(Restoration::kChannelName, &Restoration::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_MOUSE_CURSOR
  RegisterCallback(MouseCursor::kChannelName, &MouseCursor::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_GSTREAMER_EGL
  RegisterCallback(GstreamerEgl::kChannelGstreamerInitialize,
                   &GstreamerEgl::OnInitialize);
#endif
#ifdef ENABLE_PLUGIN_NAVIGATION
  RegisterCallback(Navigation::kChannelName, &Navigation::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_COMP_SURF
  RegisterCallback(CompositorSurfacePlugin::kChannelName,
                   &CompositorSurfacePlugin::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_COMP_REGION
  RegisterCallback(CompositorRegionPlugin::kChannelName,
                   &CompositorRegionPlugin::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_OPENGL_TEXTURE
  RegisterCallback(OpenGlTexture::kChannelName,
                   OpenGlTexture::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_PACKAGE_INFO
  RegisterCallback(PackageInfo::kChannelName, &PackageInfo::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_PLATFORM
  RegisterCallback(Platform::kChannelName, &Platform::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_PLATFORM_VIEWS
  RegisterCallback(PlatformViews::kChannelName,
                   &PlatformViews::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_DESKTOP_WINDOW
  RegisterCallback(DesktopWindow::kChannelName,
                   &DesktopWindow::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_TEXT_INPUT
  RegisterCallback(TextInput::kChannelName, &TextInput::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_URL_LAUNCHER
  RegisterCallback(UrlLauncher::kChannelName, &UrlLauncher::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_SECURE_STORAGE
  RegisterCallback(SecureStorage::kChannelName,
                   &SecureStorage::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_INTEGRATION_TEST
  RegisterCallback(IntegrationTestPlugin::kChannelName,
                   &IntegrationTestPlugin::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_LOGGING
  RegisterCallback(LoggingPlugin::kChannelName,
                   &LoggingPlugin::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_KEYBOARD_MANAGER
  RegisterCallback(KeyboardManager::kChannelName,
                   &KeyboardManager::OnPlatformMessage);
#endif
#ifdef ENABLE_PLUGIN_GOOGLE_SIGN_IN
  RegisterCallback(GoogleSignIn::kChannelName,
                   &GoogleSignIn::OnPlatformMessage);
#endif
}

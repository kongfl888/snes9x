/*****************************************************************************\
     Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
                This file is licensed under the Snes9x License.
   For further information, consult the LICENSE file in the root directory.
\*****************************************************************************/

/* 所有 GUI 文本字符串最终汇集于此 */

#define WINDOW_TITLE TEXT("Snes9x")

// 已不再使用 windows 注册表
//#define MY_REG_KEY   "Software\\Emulators\\Snes9x"
//#define REG_KEY_VER  "1.31"

#define DISCLAIMER_TEXT        TEXT("Snes9x v%s Windows 版。\r\n\
(c) Copyright 1996 - 2002  Gary Henderson and Jerremy Koot (jkoot@snes9x.com)\r\n\
(c) Copyright 2002 - 2004  Matthew Kendora\r\n\
(c) Copyright 2002 - 2005  Peter Bortas\r\n\
(c) Copyright 2004 - 2005  Joel Yliluoma\r\n\
(c) Copyright 2001 - 2006  John Weidman\r\n\
(c) Copyright 2002 - 2010  Brad Jorsch, funkyass, Kris Bleakley, Nach, zones\r\n\
(c) Copyright 2006 - 2007  nitsuja\r\n\
(c) Copyright 2009 - 2023  BearOso, OV2\r\n\r\n\
Windows Port Authors: Matthew Kendora, funkyass, nitsuja, Nach, blip, OV2.\r\n\r\n\
Snes9x 是一款超级任天堂娱乐系统\r\n\
（Super Nintendo Entertainment System）模拟器，\r\n\
可让您在自己的 PC 上畅玩大多数为 SNES 开发的游戏。\r\n\r\n\
本版本为自用编译，版本： gxxxxxxx - 26xxxx - 2026xxxx，\r\n\
前者表示当前拉取的 git 版本，\r\n\
中间表示该 git 版本的提交时间\r\n\
后者表示当前翻译时间或本版本分享时间。\r\n\
软件翻译：kongfl888 (KsiteCN)\r\n\
有关 Snes9x 的最新信息与帮助，请访问\r\n\
http://www.snes9x.com。\r\n\r\n\
任天堂（Nintendo）为注册商标。")


#define APP_NAME TEXT("Snes9x")
// 可能的全局字符串
#define SNES9X_INFO TEXT("Snes9x：信息")
#define SNES9X_WARN TEXT("Snes9x：警告！")
#define SNES9X_DXS TEXT("Snes9x：DirectSound")
#define SNES9X_SNDQ TEXT("Snes9x：音频 CPU 问题")
#define SNES9X_NP_ERROR TEXT("Snes9x：联机错误")
#define BUTTON_OK TEXT("确定(&O)")
#define BUTTON_CANCEL TEXT("取消(&C)")

// 手柄配置对话框字符串
#define INPUTCONFIG_TITLE TEXT("输入配置")
#define INPUTCONFIG_JPTOGGLE TEXT("启用")
//#define INPUTCONFIG_DIAGTOGGLE "切换斜向"
//#define INPUTCONFIG_OK "&OK"
//#define INPUTCONFIG_CANCEL "&Cancel"
#define INPUTCONFIG_JPCOMBO TEXT("手柄 #%d")
#define INPUTCONFIG_LABEL_UP TEXT("上")
#define INPUTCONFIG_LABEL_DOWN TEXT("下")
#define INPUTCONFIG_LABEL_LEFT TEXT("左")
#define INPUTCONFIG_LABEL_RIGHT TEXT("右")
#define INPUTCONFIG_LABEL_A TEXT("A")
#define INPUTCONFIG_LABEL_B TEXT("B")
#define INPUTCONFIG_LABEL_X TEXT("X")
#define INPUTCONFIG_LABEL_Y TEXT("Y")
#define INPUTCONFIG_LABEL_L TEXT("L")
#define INPUTCONFIG_LABEL_R TEXT("R")
#define INPUTCONFIG_LABEL_START TEXT("开始")
#define INPUTCONFIG_LABEL_SELECT TEXT("选择")
#define INPUTCONFIG_LABEL_UPLEFT TEXT("左上")
#define INPUTCONFIG_LABEL_UPRIGHT TEXT("右上")
#define INPUTCONFIG_LABEL_DOWNRIGHT TEXT("右下")
#define INPUTCONFIG_LABEL_DOWNLEFT TEXT("左下")
#define INPUTCONFIG_LABEL_BLUE TEXT("蓝色表示该按键已被映射。\n粉色表示它与自定义快捷键冲突。\n红色表示它已被 Windows 保留。\n可用 Esc 键停用按键。")
#define INPUTCONFIG_LABEL_UNUSED TEXT("")
#define INPUTCONFIG_LABEL_CLEAR_TOGGLES_AND_TURBO TEXT("全部清除")
#define INPUTCONFIG_LABEL_MAKE_TURBO TEXT("临时连发")
#define INPUTCONFIG_LABEL_MAKE_HELD TEXT("自动保持")
#define INPUTCONFIG_LABEL_MAKE_TURBO_HELD TEXT("自动连发")
#define INPUTCONFIG_LABEL_CONTROLLER_TURBO_PANEL_MOD TEXT(" 连发")

// 快捷键对话框字符串
#define HOTKEYS_TITLE TEXT("快捷键配置")
#define HOTKEYS_CONTROL_MOD "Ctrl + "
#define HOTKEYS_SHIFT_MOD "Shift + "
#define HOTKEYS_ALT_MOD "Alt + "
#define HOTKEYS_LABEL_BLUE TEXT("蓝色表示该快捷键已被映射。\n粉色表示它与游戏按键冲突。\n红色表示它已被 Windows 保留。\n可用 Esc 键停用快捷键。")
#define HOTKEYS_HKCOMBO TEXT("第 %d 页")
#define HOTKEYS_LABEL_1_1 TEXT("加速 +:")
#define HOTKEYS_LABEL_1_2 TEXT("加速 -:")
#define HOTKEYS_LABEL_1_3 TEXT("暂停:")
#define HOTKEYS_LABEL_1_4 TEXT("切换快进:")
#define HOTKEYS_LABEL_1_5 TEXT("快进:")
#define HOTKEYS_LABEL_1_6 TEXT("倒带:")
#define HOTKEYS_LABEL_1_7 TEXT("跳帧 +:")
#define HOTKEYS_LABEL_1_8 TEXT("跳帧 -:")
#define HOTKEYS_LABEL_1_9 TEXT("切换静音:")
#define HOTKEYS_LABEL_1_10 TEXT("切换金手指:")
#define HOTKEYS_LABEL_1_11 TEXT("退出 Snes9x:")
#define HOTKEYS_LABEL_1_12 TEXT("重置游戏:")
#define HOTKEYS_LABEL_1_13 TEXT("保存截图")
#define HOTKEYS_LABEL_1_14 TEXT("逐帧步进:")

#define HOTKEYS_LABEL_2_1 TEXT("图形层 1:")
#define HOTKEYS_LABEL_2_2 TEXT("图形层 2:")
#define HOTKEYS_LABEL_2_3 TEXT("图形层 3:")
#define HOTKEYS_LABEL_2_4 TEXT("图形层 4:")
#define HOTKEYS_LABEL_2_5 TEXT("精灵层:")
#define HOTKEYS_LABEL_2_6 TEXT("裁剪窗口:")
#define HOTKEYS_LABEL_2_7 TEXT("透明效果:")
#define HOTKEYS_LABEL_2_8 TEXT("切换背景色:")
#define HOTKEYS_LABEL_2_9 TEXT("SuperScope 暂停:")
#define HOTKEYS_LABEL_2_10 TEXT("切换控制器:")
#define HOTKEYS_LABEL_2_11 TEXT("手柄交换:")
#define HOTKEYS_LABEL_2_12 TEXT("显示按下的键:")
#define HOTKEYS_LABEL_2_13 TEXT("录像帧数:")
#define HOTKEYS_LABEL_2_14 TEXT("录像只读:")

#define HOTKEYS_LABEL_3_1 TEXT("Turbo A 模式:")
#define HOTKEYS_LABEL_3_2 TEXT("Turbo B 模式:")
#define HOTKEYS_LABEL_3_3 TEXT("Turbo Y 模式:")
#define HOTKEYS_LABEL_3_4 TEXT("Turbo X 模式:")
#define HOTKEYS_LABEL_3_5 TEXT("Turbo L 模式:")
#define HOTKEYS_LABEL_3_6 TEXT("Turbo R 模式:")
#define HOTKEYS_LABEL_3_7 TEXT("Turbo 开始模式:")
#define HOTKEYS_LABEL_3_8 TEXT("Turbo 选择模式:")
#define HOTKEYS_LABEL_3_9 TEXT("Turbo 左模式:")
#define HOTKEYS_LABEL_3_10 TEXT("Turbo 上模式:")
#define HOTKEYS_LABEL_3_11 TEXT("Turbo 右模式:")
#define HOTKEYS_LABEL_3_12 TEXT("Turbo 下模式:")
#define HOTKEYS_LABEL_3_13 TEXT("SuperScope 连发:")


#define HOTKEYS_LABEL_4_1 TEXT("选择存档位 0:")
#define HOTKEYS_LABEL_4_2 TEXT("选择存档位 1:")
#define HOTKEYS_LABEL_4_3 TEXT("选择存档位 2:")
#define HOTKEYS_LABEL_4_4 TEXT("选择存档位 3:")
#define HOTKEYS_LABEL_4_5 TEXT("选择存档位 4:")
#define HOTKEYS_LABEL_4_6 TEXT("选择存档位 5:")
#define HOTKEYS_LABEL_4_7 TEXT("选择存档位 6:")
#define HOTKEYS_LABEL_4_8 TEXT("选择存档位 7:")
#define HOTKEYS_LABEL_4_9 TEXT("选择存档位 8:")
#define HOTKEYS_LABEL_4_10 TEXT("选择存档位 9:")
#define HOTKEYS_LABEL_4_11 TEXT("保存到文件:")
#define HOTKEYS_LABEL_4_12 TEXT("从文件读取:")

#define HOTKEYS_SWITCH_ASPECT_RATIO TEXT("切换宽高比:")
#define HOTKEYS_CHEAT_EDITOR_DIALOG TEXT("金手指编辑器:")
#define HOTKEYS_CHEAT_SEARCH_DIALOG TEXT("金手指搜索框:")

// 游戏按键与轴向
#define GAMEDEVICE_JOYNUMPREFIX "(J%x)" // don't change this
#define GAMEDEVICE_JOYBUTPREFIX "#[%d]" // don't change this
#define GAMEDEVICE_XNEG "Left"
#define GAMEDEVICE_XPOS "Right"
#define GAMEDEVICE_YPOS "Up"
#define GAMEDEVICE_YNEG "Down"
#define GAMEDEVICE_POVLEFT "POV Left"
#define GAMEDEVICE_POVRIGHT "POV Right"
#define GAMEDEVICE_POVUP "POV Up"
#define GAMEDEVICE_POVDOWN "POV Down"
#define GAMEDEVICE_POVDNLEFT "POV Dn Left"
#define GAMEDEVICE_POVDNRIGHT "POV Dn Right"
#define GAMEDEVICE_POVUPLEFT  "POV Up Left"
#define GAMEDEVICE_POVUPRIGHT "POV Up Right"
#define GAMEDEVICE_ZPOS "Z Up"
#define GAMEDEVICE_ZNEG "Z Down"
#define GAMEDEVICE_RPOS "R Up"
#define GAMEDEVICE_RNEG "R Down"
#define GAMEDEVICE_UPOS "U Up"
#define GAMEDEVICE_UNEG "U Down"
#define GAMEDEVICE_VPOS "V Up"
#define GAMEDEVICE_VNEG "V Down"
#define GAMEDEVICE_BUTTON "Button %d"

// gaming general
#define GAMEDEVICE_DISABLED "Disabled"

// gaming keys
#define GAMEDEVICE_KEY "#%d"
#define GAMEDEVICE_NUMPADPREFIX "Numpad-%c"
#define GAMEDEVICE_VK_TAB "Tab"
#define GAMEDEVICE_VK_BACK "Backspace"
#define GAMEDEVICE_VK_CLEAR "Clear"
#define GAMEDEVICE_VK_RETURN "Enter"
#define GAMEDEVICE_VK_LSHIFT "LShift"
#define GAMEDEVICE_VK_RSHIFT "RShift"
#define GAMEDEVICE_VK_LCONTROL "LCtrl"
#define GAMEDEVICE_VK_RCONTROL "RCtrl"
#define GAMEDEVICE_VK_LMENU "LAlt"
#define GAMEDEVICE_VK_RMENU "RAlt"
#define GAMEDEVICE_VK_PAUSE "Pause"
#define GAMEDEVICE_VK_CAPITAL "Capslock"
#define GAMEDEVICE_VK_ESCAPE "Disabled"
#define GAMEDEVICE_VK_SPACE "Space"
#define GAMEDEVICE_VK_PRIOR "PgUp"
#define GAMEDEVICE_VK_NEXT "PgDn"
#define GAMEDEVICE_VK_HOME "Home"
#define GAMEDEVICE_VK_END "End"
#define GAMEDEVICE_VK_LEFT "Left"
#define GAMEDEVICE_VK_RIGHT "Right"
#define GAMEDEVICE_VK_UP "Up"
#define GAMEDEVICE_VK_DOWN "Down"
#define GAMEDEVICE_VK_SELECT "Select"
#define GAMEDEVICE_VK_PRINT "Print"
#define GAMEDEVICE_VK_EXECUTE "Execute"
#define GAMEDEVICE_VK_SNAPSHOT "SnapShot"
#define GAMEDEVICE_VK_INSERT "Insert"
#define GAMEDEVICE_VK_DELETE "Delete"
#define GAMEDEVICE_VK_HELP "Help"
#define GAMEDEVICE_VK_LWIN "LWinKey"
#define GAMEDEVICE_VK_RWIN "RWinKey"
#define GAMEDEVICE_VK_APPS "AppKey"
#define GAMEDEVICE_VK_MULTIPLY "Numpad *"
#define GAMEDEVICE_VK_ADD "Numpad +"
#define GAMEDEVICE_VK_SEPARATOR "Separator"
#define GAMEDEVICE_VK_OEM_1 ";"
#define GAMEDEVICE_VK_OEM_7 "\""
#define GAMEDEVICE_VK_OEM_COMMA ","
#define GAMEDEVICE_VK_OEM_PERIOD "."
#define GAMEDEVICE_VK_SUBTRACT "Numpad -"
#define GAMEDEVICE_VK_DECIMAL "Numpad ."
#define GAMEDEVICE_VK_DIVIDE "Numpad /"
#define GAMEDEVICE_VK_NUMLOCK "Num-lock"
#define GAMEDEVICE_VK_SCROLL "Scroll-lock"
#define GAMEDEVICE_VK_OEM_MINUS "-"
#define GAMEDEVICE_VK_OEM_PLUS "="
#define GAMEDEVICE_VK_SHIFT "Shift"
#define GAMEDEVICE_VK_CONTROL "Control"
#define GAMEDEVICE_VK_MENU "Alt"
#define GAMEDEVICE_VK_OEM_4 "["
#define GAMEDEVICE_VK_OEM_6 "]"
#define GAMEDEVICE_VK_OEM_5 "\\"
#define GAMEDEVICE_VK_OEM_2 "/"
#define GAMEDEVICE_VK_OEM_3 "`"
#define GAMEDEVICE_VK_F1 "F1"
#define GAMEDEVICE_VK_F2 "F2"
#define GAMEDEVICE_VK_F3 "F3"
#define GAMEDEVICE_VK_F4 "F4"
#define GAMEDEVICE_VK_F5 "F5"
#define GAMEDEVICE_VK_F6 "F6"
#define GAMEDEVICE_VK_F7 "F7"
#define GAMEDEVICE_VK_F8 "F8"
#define GAMEDEVICE_VK_F9 "F9"
#define GAMEDEVICE_VK_F10 "F10"
#define GAMEDEVICE_VK_F11 "F11"
#define GAMEDEVICE_VK_F12 "F12"


//evil things I found in WinProc

#define WINPROC_TURBOMODE_ON "Fast-Forward Activated"
#define WINPROC_TURBOMODE_OFF "Fast-Forward Deactivated"
#define WINPROC_TURBOMODE_TEXT "Fast-Forward"
#define WINPROC_BG1 "BG#1" //Background Layers
#define WINPROC_BG2 "BG#2"
#define WINPROC_BG3 "BG#3"
#define WINPROC_BG4 "BG#4"
#define WINPROC_SPRITES "Sprites"
#define WINPROC_PADSWAP "Joypad swapping"
#define WINPROC_CONTROLERS0 "Multiplayer 5 on #0"
#define WINPROC_CONTROLERS1 "Joypad on #0"
#define WINPROC_CONTROLERS2 "Mouse on #1"
#define WINPROC_CONTROLERS3 "Mouse on #0"
#define WINPROC_CONTROLERS4 "Superscope on #1"
#define WINPROC_CONTROLERS5 "Justifier 1 on #1"
#define WINPROC_CONTROLERS6 "Justifier 2 on #1"
#define WINPROC_CONTROLERS7 "M.A.C.S. Rifle on #1"
#define WINPROC_BGHACK "Background layering hack"
#define WINPROC_MODE7INTER "Mode 7 Interpolation"
#define WINPROC_TRANSPARENCY "Transparency effects"
#define WINPROC_CLIPWIN "Graphic clip windows"
#define WINPROC_PAUSE "Pause"
#define WINPROC_EMUFRAMETIME "Emulated frame time: %dms"
#define WINPROC_AUTOSKIP "Auto Frame Skip"
#define WINPROC_FRAMESKIP "Frame skip: %d"
#define WINPROC_TURBO_R_ON "Turbo R Activated"
#define WINPROC_TURBO_R_OFF "Turbo R Deactivated"
#define WINPROC_TURBO_L_ON "Turbo L Activated"
#define WINPROC_TURBO_L_OFF "Turbo L Deactivated"
#define WINPROC_TURBO_X_ON "Turbo X Activated"
#define WINPROC_TURBO_X_OFF "Turbo X Deactivated"
#define WINPROC_TURBO_Y_ON "Turbo Y Activated"
#define WINPROC_TURBO_Y_OFF "Turbo Y Deactivated"
#define WINPROC_TURBO_A_ON "Turbo A Activated"
#define WINPROC_TURBO_A_OFF "Turbo A Deactivated"
#define WINPROC_TURBO_B_ON "Turbo B Activated"
#define WINPROC_TURBO_B_OFF "Turbo B Deactivated"
#define WINPROC_TURBO_SEL_ON "Turbo Select Activated"
#define WINPROC_TURBO_SEL_OFF "Turbo Select Deactivated"
#define WINPROC_TURBO_START_ON "Turbo Start Activated"
#define WINPROC_TURBO_START_OFF "Turbo Start Deactivated"
#define WINPROC_TURBO_LEFT_ON "Turbo Left Activated"
#define WINPROC_TURBO_LEFT_OFF "Turbo Left Deactivated"
#define WINPROC_TURBO_RIGHT_ON "Turbo Right Activated"
#define WINPROC_TURBO_RIGHT_OFF "Turbo Right Deactivated"
#define WINPROC_TURBO_UP_ON "Turbo Up Activated"
#define WINPROC_TURBO_UP_OFF "Turbo Up Deactivated"
#define WINPROC_TURBO_DOWN_ON "Turbo Down Activated"
#define WINPROC_TURBO_DOWN_OFF "Turbo Down Deactivated"
#define WINPROC_FILTER_RESTART "You will need to restart Snes9x before the output image\nprocessing option change will take effect."
#define WINPROC_DISCONNECT "Disconnect from the NetPlay server first."
#define WINPROC_NET_RESTART "Your game will be reset after the ROM has been sent due to\nyour 'Sync Using Reset Game' setting.\n\n"
#define WINPROC_SYNC_SND "Sync sound"
#define WINPROC_REWINDING_TEXT "Rewinding"
#define WINPROC_REWINDING_DISABLED "Rewind is disabled"

//模拟设置

#define EMUSET_TITLE TEXT("模拟设置")
#define EMUSET_LABEL_DIRECTORY TEXT("目录")
#define EMUSET_BROWSE TEXT("&浏览...")
#define EMUSET_LABEL_ASRAM TEXT("自动保存 S-RAM")
#define EMUSET_LABEL_ASRAM_TEXT TEXT("秒距上次更改后（0 表示禁用自动保存）")
#define EMUSET_LABEL_SMAX TEXT("最多跳过")
#define EMUSET_LABEL_SMAX_TEXT TEXT("帧（自动帧率模式）")
#define EMUSET_LABEL_STURBO TEXT("跳过渲染")
#define EMUSET_LABEL_STURBO_TEXT TEXT("帧（快进模式）")

//联机选项

#define NPOPT_TITLE TEXT("联机选项")
#define NPOPT_LABEL_PORTNUM TEXT("套接字端口号")
#define NPOPT_LABEL_PAUSEINTERVAL TEXT("当落后")
#define NPOPT_LABEL_PAUSEINTERVAL_TEXT TEXT("帧时请求服务器暂停")
#define NPOPT_LABEL_MAXSKIP TEXT("最大帧率跳过")
#define NPOPT_SYNCBYRESET TEXT("通过重置同步")
#define NPOPT_SENDROM TEXT("连接时将 ROM 镜像发送给客户端")
#define NPOPT_ACTASSERVER TEXT("作为服务器")
#define NPOPT_PORTNUMBLOCK TEXT("端口设置")
#define NPOPT_CLIENTSETTINGSBLOCK TEXT("客户端设置")
#define NPOPT_SERVERSETTINGSBLOCK TEXT("服务器设置")

//联机连接


#define NPCON_TITLE TEXT("连接到服务器")
#define NPCON_LABEL_SERVERADDY TEXT("服务器地址")
#define NPCON_LABEL_PORTNUM TEXT("端口号")
#define NPCON_CLEARHISTORY TEXT("清除历史")
#define NPCON_ENTERHOST TEXT("输入主机名...")
#define NPCON_PLEASE_ENTERHOST TEXT("请输入主机名。")


//录像消息

#define MOVIE_FILETYPE_DESCRIPTION TEXT("Snes9x 录像文件")
#define MOVIE_LABEL_SYNC_DATA_FROM_MOVIE TEXT("从录像加载：")
#define MOVIE_LABEL_SYNC_DATA_NOT_FROM_MOVIE TEXT("设置不在录像中；请核对：")
#define MOVIE_ERR_COULD_NOT_OPEN TEXT("无法打开录像文件。")
#define MOVIE_ERR_NOT_FOUND_SHORT TEXT("找不到文件。")
#define MOVIE_ERR_NOT_FOUND TEXT("找不到录像文件，或无法打开。")
#define MOVIE_ERR_WRONG_FORMAT_SHORT TEXT("无法识别的格式。")
#define MOVIE_ERR_WRONG_FORMAT TEXT("录像文件已损坏或格式错误。")
#define MOVIE_ERR_WRONG_VERSION_SHORT TEXT("不支持的录像版本。")
#define MOVIE_ERR_WRONG_VERSION MOVIE_ERR_WRONG_VERSION_SHORT TEXT(" 你需要其他版本的 Snes9x 才能播放此录像。")
#define MOVIE_ERR_NOFRAMETOGGLE "No movie; can't toggle frame count"
#define MOVIE_ERR_NOREADONLYTOGGLE "No movie; can't toggle read-only"
#define MOVIE_LABEL_AUTHORINFO TEXT("作者信息：")
#define MOVIE_LABEL_ERRORINFO TEXT("错误信息：")
#define MOVIE_INFO_MISMATCH TEXT(" <-- 不匹配！！！")
#define MOVIE_INFO_CURRENTROM TEXT("当前 ROM：")
#define MOVIE_INFO_MOVIEROM TEXT("录像的 ROM：")
#define MOVIE_INFO_ROMNOTSTORED TEXT("（未存储于录像文件中）")
#define MOVIE_INFO_ROMINFO TEXT(" crc32=%08X, name=%s")
#define MOVIE_INFO_DIRECTORY TEXT(" 路径：%s")
#define MOVIE_WARNING_MISMATCH TEXT("警告：你没有载入正确的 ROM！")
#define MOVIE_WARNING_OK TEXT("按“确定”开始播放录像。")
#define MOVIE_LABEL_STARTSETTINGS TEXT("录制开始")
#define MOVIE_LABEL_CONTSETTINGS TEXT("录制控制器")
#define MOVIE_LABEL_SYNCSETTINGS TEXT("其他录制设置")

// Save Messages

#define FREEZE_INFO_SET_SLOT_N "Set save slot %03d, bank %03d [%s]"

// AVI Messages

#define AVI_CONFIGURATION_CHANGED "AVI recording stopped (configuration settings changed)."
#define AVI_CREATION_FAILED "Failed to create AVI file."

// 金手指或金手指搜索消息

#define SEARCH_TITLE_RANGEERROR TEXT("范围错误")
#define SEARCH_TITLE_CHEATERROR TEXT("Snes9x 金手指错误")
#define SEARCH_ERR_INVALIDNEWVALUE TEXT("你为新值输入了超出范围或无效的值")
#define SEARCH_ERR_INVALIDCURVALUE TEXT("你为当前值输入了超出范围或无效的值。\n\
                                   该值会在金手指未应用时被使用。\n\
                                   （若留空，则金手指未应用时不会恢复任何值）")
#define SEARCH_ERR_INVALIDSEARCHVALUE TEXT("请输入有效的搜索值！")
#define SEARCH_COLUMN_CODE TEXT("代码")
#define SEARCH_COLUMN_ADDRESS TEXT("地址")
#define SEARCH_COLUMN_VALUE TEXT("数值")
#define SEARCH_COLUMN_DESCRIPTION TEXT("描述")

// ROM 对话框

#define ROM_COLUMN_FILENAME TEXT("文件")
#define ROM_COLUMN_DESCRIPTION TEXT("描述")
#define ROM_COLUMN_SIZE TEXT("大小")
#define ROM_OPTION_AUTODETECT TEXT("自动检测")
#define ROM_OPTION_FORCEHEADER TEXT("强制带文件头")
#define ROM_OPTION_FORCENOHEADER TEXT("强制无文件头")
#define ROM_OPTION_FORCEPAL TEXT("强制 PAL")
#define ROM_OPTION_FORCENTSC TEXT("强制 NTSC")
#define ROM_OPTION_FORCEHIROM TEXT("强制 HiROM")
#define ROM_OPTION_FORCELOROM TEXT("强制 LoROM")
#define ROM_OPTION_NONINTERLEAVED TEXT("强制非交错")
#define ROM_OPTION_MODE1 TEXT("强制模式 1")
#define ROM_OPTION_MODE2 TEXT("强制模式 2")
#define ROM_OPTION_GD24 TEXT("强制 GD24")
#define ROM_ITEM_NOTAROM TEXT("不是 ROM")
#define ROM_ITEM_CANTOPEN TEXT("无法打开文件")
#define ROM_ITEM_DESCNOTAVAILABLE TEXT("（不可用）")
#define ROM_ITEM_COMPRESSEDROMDESCRIPTION TEXT("")

// 设置

#define SETTINGS_TITLE_SELECTFOLDER TEXT("选择文件夹")
#define SETTINGS_OPTION_DIRECTORY_ROMS TEXT("ROM")
#define SETTINGS_OPTION_DIRECTORY_SCREENS TEXT("截图")
#define SETTINGS_OPTION_DIRECTORY_MOVIES TEXT("录像")
#define SETTINGS_OPTION_DIRECTORY_SPCS TEXT("SPC")
#define SETTINGS_OPTION_DIRECTORY_SAVES TEXT("存档")
#define SETTINGS_OPTION_DIRECTORY_SRAM TEXT("SRAM")
#define SETTINGS_OPTION_DIRECTORY_PATCHES TEXT("补丁")
#define SETTINGS_OPTION_DIRECTORY_CHEATS TEXT("金手指")
#define SETTINGS_OPTION_DIRECTORY_BIOS TEXT("BIOS")
#define SETTINGS_OPTION_DIRECTORY_SATDATA TEXT("Satellaview")

// Misc.

#define INPUT_INFO_DISPLAY_ENABLED "Input display enabled."
#define INPUT_INFO_DISPLAY_DISABLED "Input display disabled."

#define FILE_INFO_AVI_FILE_TYPE TEXT("AVI 文件")
#define FILE_INFO_TXT_FILE_TYPE TEXT("文本文件")
#define FILE_INFO_ROM_FILE_TYPE TEXT("ROM 文件或压缩包")
#define FILE_INFO_UNCROM_FILE_TYPE TEXT("未压缩的 ROM 文件")
#define FILE_INFO_ANY_FILE_TYPE TEXT("所有文件")

#define ERR_ROM_NOT_FOUND "ROM image \"%s\" was not found or could not be opened."
#define SRM_SAVE_FAILED "Failed to save SRM file."

#define INFO_SAVE_SPC "Saving SPC Data."

#define MPAK_SAVE_FAILED "Failed to save Memory Pack."

#define CHEATS_INFO_ENABLED "Cheats enabled."
#define CHEATS_INFO_DISABLED "Cheats disabled."
#define CHEATS_INFO_ENABLED_NONE "Cheats enabled. (None are active.)"

#define MULTICART_BIOS_NOT_FOUND TEXT("未找到！")
#define MULTICART_BIOS_FOUND TEXT("")

#define ABOUT_DIALOG_TITLE TEXT("关于 ")

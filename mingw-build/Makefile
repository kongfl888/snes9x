# MinGW-w64 cross build of the Snes9x win32 frontend.
# Mirrors the Release|Win32 configuration of win32/snes9xw.vcxproj (including
# its ExcludedFromBuild entries) and produces snes9x.exe.

CXX = i686-w64-mingw32-g++-posix
CC  = i686-w64-mingw32-gcc-posix
RC  = i686-w64-mingw32-windres
GLSLANG = $(CURDIR)/../glslang-build-i686

OBJS = obj/apu_apu.o obj/apu_bapu_dsp_sdsp.o obj/apu_bapu_smp_smp.o obj/apu_bapu_smp_smp_state.o obj/bsx.o obj/c4.o obj/c4emu.o obj/cheats.o obj/cheats2.o obj/clip.o obj/conffile.o obj/controls.o obj/cpu.o obj/cpuexec.o obj/cpuops.o obj/crosshairs.o obj/debug.o obj/dma.o obj/dsp.o obj/dsp1.o obj/dsp2.o obj/dsp3.o obj/dsp4.o obj/external_imgui_imgui.o obj/external_imgui_imgui_demo.o obj/external_imgui_imgui_draw.o obj/external_imgui_imgui_impl_dx9.o obj/external_imgui_imgui_impl_opengl3.o obj/external_imgui_imgui_impl_vulkan.o obj/external_imgui_imgui_tables.o obj/external_imgui_imgui_widgets.o obj/external_imgui_snes9x_imgui.o obj/external_stb_stb_image_implementation.o obj/filter_2xsai.o obj/filter_blit.o obj/filter_epx.o obj/filter_sharpbilinear_flexible.o obj/filter_hq2x.o obj/filter_snes_ntsc.o obj/filter_xbrz.o obj/fscompat.o obj/fxemu.o obj/fxinst.o obj/gfx.o obj/globals.o obj/jma_7zlzma.o obj/jma_crc32.o obj/jma_iiostrm.o obj/jma_inbyte.o obj/jma_jma.o obj/jma_lzma.o obj/jma_lzmadec.o obj/jma_s9x-jma.o obj/jma_winout.o obj/loadzip.o obj/memmap.o obj/movie.o obj/msu1.o obj/netplay.o obj/obc1.o obj/ppu.o obj/sa1.o obj/sa1cpu.o obj/screenshot.o obj/sdd1.o obj/sdd1emu.o obj/server.o obj/seta.o obj/seta010.o obj/seta011.o obj/seta018.o obj/common_video_opengl_shaders_glsl.o obj/common_video_opengl_shaders_shader_helpers.o obj/common_video_opengl_shaders_slang.o obj/external_SPIRV-Cross_spirv_cfg.o obj/external_SPIRV-Cross_spirv_cross.o obj/external_SPIRV-Cross_spirv_cross_parsed_ir.o obj/external_SPIRV-Cross_spirv_glsl.o obj/external_SPIRV-Cross_spirv_parser.o obj/snapshot.o obj/snes9x.o obj/spc7110.o obj/srtc.o obj/statemanager.o obj/sha256.o obj/bml.o obj/stream.o obj/tile.o obj/tileimpl-n1x1.o obj/tileimpl-n2x1.o obj/tileimpl-h2x1.o obj/unzip_ioapi.o obj/unzip_iowin32.o obj/unzip_mztools.o obj/unzip_unzip.o obj/unzip_zip.o obj/common_video_vulkan_slang_helpers.o obj/common_video_vulkan_slang_preset.o obj/common_video_vulkan_slang_preset_ini.o obj/common_video_vulkan_slang_preset_test.o obj/common_video_vulkan_slang_shader.o obj/common_video_vulkan_vk_mem_alloc_implementation.o obj/common_video_vulkan_vulkan_context.o obj/common_video_vulkan_vulkan_common.o obj/common_video_vulkan_vulkan_hpp_storage.o obj/common_video_vulkan_vulkan_pipeline_image.o obj/common_video_vulkan_vulkan_shader_chain.o obj/common_video_vulkan_vulkan_simple_output.o obj/common_video_vulkan_vulkan_slang_pipeline.o obj/common_video_vulkan_vulkan_swapchain.o obj/common_video_vulkan_vulkan_texture.o obj/AVIOutput.o obj/CCGShader.o obj/CCheatGroupDialog.o obj/CD3DCG.o obj/CDirect3D.o obj/CDirectDraw.o obj/cgFunctions.o obj/CGLCG.o obj/CSaveLoadWithPreviewDlg.o obj/COpenGL.o obj/CShaderParamDlg.o obj/CVulkan.o obj/CWaveOut.o obj/CXAudio2.o obj/DumpAtEnd.o obj/gl_core_3_1.o obj/image_functions.o obj/InputCustom.o obj/render.o obj/wconfig.o obj/win32.o obj/win32_display.o obj/win32_sound.o obj/wsnes9x.o obj/_tfwopen.o obj/win32_zlib_src_adler32.o obj/win32_zlib_src_compress.o obj/win32_zlib_src_crc32.o obj/win32_zlib_src_deflate.o obj/win32_zlib_src_gzclose.o obj/win32_zlib_src_gzlib.o obj/win32_zlib_src_gzread.o obj/win32_zlib_src_gzwrite.o obj/win32_zlib_src_infback.o obj/win32_zlib_src_inffast.o obj/win32_zlib_src_inflate.o obj/win32_zlib_src_inftrees.o obj/win32_zlib_src_trees.o obj/win32_zlib_src_uncompr.o obj/win32_zlib_src_zutil.o obj/win32_libpng_src_png.o obj/win32_libpng_src_pngerror.o obj/win32_libpng_src_pngget.o obj/win32_libpng_src_pngmem.o obj/win32_libpng_src_pngpread.o obj/win32_libpng_src_pngread.o obj/win32_libpng_src_pngrio.o obj/win32_libpng_src_pngrtran.o obj/win32_libpng_src_pngrutil.o obj/win32_libpng_src_pngset.o obj/win32_libpng_src_pngtrans.o obj/win32_libpng_src_pngwio.o obj/win32_libpng_src_pngwrite.o obj/win32_libpng_src_pngwtran.o obj/win32_libpng_src_pngwutil.o

DEFS = -DNDEBUG -DUNICODE -D_UNICODE -D_WIN32_WINNT=0x0601 -DALLOW_CPU_OVERCLOCK \
       -DHAVE_LIBPNG -DJMA_SUPPORT -DZLIB -DUNZIP_SUPPORT -D__WIN32__ \
       -DNETPLAY_SUPPORT -DDIRECTDRAW_SUPPORT -DUSE_SLANG \
       -DVK_USE_PLATFORM_WIN32_KHR -DVULKAN_HPP_DISPATCH_LOADER_DYNAMIC=1 \
       -DVULKAN_HPP_NO_EXCEPTIONS=1 -DVULKAN_HPP_NO_NODISCARD_WARNINGS=1 \
       -DVMA_DYNAMIC_VULKAN_FUNCTIONS=1 -DVMA_STATIC_VULKAN_FUNCTIONS=0 \
       -DVMA_USE_STL_SHARED_MUTEX=0 -DIMGUI_IMPL_VULKAN_NO_PROTOTYPES

INCS = -I../mingw_shim/case -I../snes9x/win32 -I../snes9x -I../snes9x/win32/zlib/src \
       -I../snes9x/unzip -Igen -I../snes9x/win32/libpng/src -I../snes9x/apu/bapu \
       -I../snes9x/external/glslang -I../snes9x/external/stb \
       -I../snes9x/external/vulkan-headers/include \
       -I../snes9x/external/VulkanMemoryAllocator-Hpp/include -I../snes9x/external/imgui \
       -I../mingw_shim

CXXFLAGS = -std=gnu++17 -O2 -fno-strict-aliasing -Wno-cpp -Wno-write-strings \
           -include ../mingw_compat.h -include _tfwopen.h
CFLAGS   = -O2 -Wno-cpp

LIBS = -lcomctl32 -lwinmm -lopengl32 -lglu32 -lwsock32 -ldsound -ldxguid -lvfw32 \
       -lshlwapi -lgdi32 -luser32 -lole32 -loleaut32 -luuid -lcomdlg32 \
       -ladvapi32 -lshell32 -ld3d9 -lddraw -lxaudio2_8 -ldwmapi -luxtheme -lpropsys \
       -static -static-libgcc -static-libstdc++

all: snes9x.exe

obj:
	mkdir -p obj

snes9x.exe: $(OBJS) obj/mingw_guids.o obj/snes9x.res.o
	$(CXX) -mwindows -o $@ $(OBJS) obj/mingw_guids.o obj/snes9x.res.o \
	  $(GLSLANG)/glslang/libglslang.a $(GLSLANG)/glslang/libglslang-default-resource-limits.a \
	  $(GLSLANG)/glslang/libGenericCodeGen.a $(GLSLANG)/SPIRV/libSPIRV.a $(GLSLANG)/SPIRV/libSPVRemapper.a \
	  $(LIBS)

obj/mingw_guids.o: ../mingw_guids.cpp | obj
	$(CXX) -std=gnu++17 -O2 -DUNICODE -D_UNICODE -I../mingw_shim -c $< -o $@

obj/snes9x.res.o: ../snes9x/win32/rsrc/snes9x.rc | obj
	$(RC) -DS9X_MINGW_RC $(DEFS) $(INCS) -I../snes9x/win32/rsrc -O coff -o $@ $<

clean:
	rm -rf obj snes9x.exe

obj/apu_apu.o: ../snes9x/apu/apu.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/apu_bapu_dsp_sdsp.o: ../snes9x/apu/bapu/dsp/sdsp.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/apu_bapu_smp_smp.o: ../snes9x/apu/bapu/smp/smp.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/apu_bapu_smp_smp_state.o: ../snes9x/apu/bapu/smp/smp_state.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/bsx.o: ../snes9x/bsx.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/c4.o: ../snes9x/c4.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/c4emu.o: ../snes9x/c4emu.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/cheats.o: ../snes9x/cheats.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/cheats2.o: ../snes9x/cheats2.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/clip.o: ../snes9x/clip.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/conffile.o: ../snes9x/conffile.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/controls.o: ../snes9x/controls.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/cpu.o: ../snes9x/cpu.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/cpuexec.o: ../snes9x/cpuexec.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/cpuops.o: ../snes9x/cpuops.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/crosshairs.o: ../snes9x/crosshairs.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/debug.o: ../snes9x/debug.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/dma.o: ../snes9x/dma.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/dsp.o: ../snes9x/dsp.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/dsp1.o: ../snes9x/dsp1.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/dsp2.o: ../snes9x/dsp2.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/dsp3.o: ../snes9x/dsp3.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/dsp4.o: ../snes9x/dsp4.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_imgui.o: ../snes9x/external/imgui/imgui.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_imgui_demo.o: ../snes9x/external/imgui/imgui_demo.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_imgui_draw.o: ../snes9x/external/imgui/imgui_draw.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_imgui_impl_dx9.o: ../snes9x/external/imgui/imgui_impl_dx9.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_imgui_impl_opengl3.o: ../snes9x/external/imgui/imgui_impl_opengl3.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_imgui_impl_vulkan.o: ../snes9x/external/imgui/imgui_impl_vulkan.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_imgui_tables.o: ../snes9x/external/imgui/imgui_tables.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_imgui_widgets.o: ../snes9x/external/imgui/imgui_widgets.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_imgui_snes9x_imgui.o: ../snes9x/external/imgui/snes9x_imgui.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_stb_stb_image_implementation.o: ../snes9x/external/stb/stb_image_implementation.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/filter_2xsai.o: ../snes9x/filter/2xsai.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/filter_blit.o: ../snes9x/filter/blit.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/filter_epx.o: ../snes9x/filter/epx.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/filter_sharpbilinear_flexible.o: ../snes9x/filter/sharpbilinear_flexible.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/filter_hq2x.o: ../snes9x/filter/hq2x.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/filter_snes_ntsc.o: ../snes9x/filter/snes_ntsc.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/filter_xbrz.o: ../snes9x/filter/xbrz.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/fscompat.o: ../snes9x/fscompat.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/fxemu.o: ../snes9x/fxemu.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/fxinst.o: ../snes9x/fxinst.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/gfx.o: ../snes9x/gfx.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/globals.o: ../snes9x/globals.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_7zlzma.o: ../snes9x/jma/7zlzma.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_crc32.o: ../snes9x/jma/crc32.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_iiostrm.o: ../snes9x/jma/iiostrm.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_inbyte.o: ../snes9x/jma/inbyte.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_jma.o: ../snes9x/jma/jma.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_lzma.o: ../snes9x/jma/lzma.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_lzmadec.o: ../snes9x/jma/lzmadec.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_s9x-jma.o: ../snes9x/jma/s9x-jma.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/jma_winout.o: ../snes9x/jma/winout.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/loadzip.o: ../snes9x/loadzip.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/memmap.o: ../snes9x/memmap.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/movie.o: ../snes9x/movie.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/msu1.o: ../snes9x/msu1.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/netplay.o: ../snes9x/netplay.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/obc1.o: ../snes9x/obc1.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/ppu.o: ../snes9x/ppu.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/sa1.o: ../snes9x/sa1.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/sa1cpu.o: ../snes9x/sa1cpu.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/screenshot.o: ../snes9x/screenshot.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/sdd1.o: ../snes9x/sdd1.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/sdd1emu.o: ../snes9x/sdd1emu.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/server.o: ../snes9x/server.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/seta.o: ../snes9x/seta.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/seta010.o: ../snes9x/seta010.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/seta011.o: ../snes9x/seta011.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/seta018.o: ../snes9x/seta018.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_opengl_shaders_glsl.o: ../snes9x/common/video/opengl/shaders/glsl.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_opengl_shaders_shader_helpers.o: ../snes9x/common/video/opengl/shaders/shader_helpers.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_opengl_shaders_slang.o: ../snes9x/common/video/opengl/shaders/slang.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_SPIRV-Cross_spirv_cfg.o: ../snes9x/external/SPIRV-Cross/spirv_cfg.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_SPIRV-Cross_spirv_cross.o: ../snes9x/external/SPIRV-Cross/spirv_cross.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_SPIRV-Cross_spirv_cross_parsed_ir.o: ../snes9x/external/SPIRV-Cross/spirv_cross_parsed_ir.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_SPIRV-Cross_spirv_glsl.o: ../snes9x/external/SPIRV-Cross/spirv_glsl.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/external_SPIRV-Cross_spirv_parser.o: ../snes9x/external/SPIRV-Cross/spirv_parser.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/snapshot.o: ../snes9x/snapshot.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/snes9x.o: ../snes9x/snes9x.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/spc7110.o: ../snes9x/spc7110.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/srtc.o: ../snes9x/srtc.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/statemanager.o: ../snes9x/statemanager.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/sha256.o: ../snes9x/sha256.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/bml.o: ../snes9x/bml.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/stream.o: ../snes9x/stream.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/tile.o: ../snes9x/tile.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/tileimpl-n1x1.o: ../snes9x/tileimpl-n1x1.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/tileimpl-n2x1.o: ../snes9x/tileimpl-n2x1.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/tileimpl-h2x1.o: ../snes9x/tileimpl-h2x1.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/unzip_ioapi.o: ../snes9x/unzip/ioapi.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/unzip_iowin32.o: ../snes9x/unzip/iowin32.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/unzip_mztools.o: ../snes9x/unzip/mztools.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/unzip_unzip.o: ../snes9x/unzip/unzip.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/unzip_zip.o: ../snes9x/unzip/zip.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_slang_helpers.o: ../snes9x/common/video/vulkan/slang_helpers.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_slang_preset.o: ../snes9x/common/video/vulkan/slang_preset.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_slang_preset_ini.o: ../snes9x/common/video/vulkan/slang_preset_ini.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_slang_preset_test.o: ../snes9x/common/video/vulkan/slang_preset_test.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_slang_shader.o: ../snes9x/common/video/vulkan/slang_shader.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vk_mem_alloc_implementation.o: ../snes9x/common/video/vulkan/vk_mem_alloc_implementation.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_context.o: ../snes9x/common/video/vulkan/vulkan_context.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_common.o: ../snes9x/common/video/vulkan/vulkan_common.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_hpp_storage.o: ../snes9x/common/video/vulkan/vulkan_hpp_storage.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_pipeline_image.o: ../snes9x/common/video/vulkan/vulkan_pipeline_image.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_shader_chain.o: ../snes9x/common/video/vulkan/vulkan_shader_chain.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_simple_output.o: ../snes9x/common/video/vulkan/vulkan_simple_output.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_slang_pipeline.o: ../snes9x/common/video/vulkan/vulkan_slang_pipeline.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_swapchain.o: ../snes9x/common/video/vulkan/vulkan_swapchain.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/common_video_vulkan_vulkan_texture.o: ../snes9x/common/video/vulkan/vulkan_texture.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/AVIOutput.o: ../snes9x/win32/AVIOutput.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CCGShader.o: ../snes9x/win32/CCGShader.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CCheatGroupDialog.o: ../snes9x/win32/CCheatGroupDialog.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CD3DCG.o: ../snes9x/win32/CD3DCG.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CDirect3D.o: ../snes9x/win32/CDirect3D.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CDirectDraw.o: ../snes9x/win32/CDirectDraw.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/cgFunctions.o: ../snes9x/win32/cgFunctions.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CGLCG.o: ../snes9x/win32/CGLCG.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CSaveLoadWithPreviewDlg.o: ../snes9x/win32/CSaveLoadWithPreviewDlg.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/COpenGL.o: ../snes9x/win32/COpenGL.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CShaderParamDlg.o: ../snes9x/win32/CShaderParamDlg.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CVulkan.o: ../snes9x/win32/CVulkan.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CWaveOut.o: ../snes9x/win32/CWaveOut.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/CXAudio2.o: ../snes9x/win32/CXAudio2.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/DumpAtEnd.o: ../snes9x/win32/DumpAtEnd.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/gl_core_3_1.o: ../snes9x/win32/gl_core_3_1.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/image_functions.o: ../snes9x/win32/image_functions.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/InputCustom.o: ../snes9x/win32/InputCustom.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/render.o: ../snes9x/win32/render.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/wconfig.o: ../snes9x/win32/wconfig.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32.o: ../snes9x/win32/win32.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_display.o: ../snes9x/win32/win32_display.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_sound.o: ../snes9x/win32/win32_sound.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/wsnes9x.o: ../snes9x/win32/wsnes9x.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/_tfwopen.o: ../snes9x/win32/_tfwopen.cpp | obj
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_adler32.o: ../snes9x/win32/zlib/src/adler32.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_compress.o: ../snes9x/win32/zlib/src/compress.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_crc32.o: ../snes9x/win32/zlib/src/crc32.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_deflate.o: ../snes9x/win32/zlib/src/deflate.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_gzclose.o: ../snes9x/win32/zlib/src/gzclose.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_gzlib.o: ../snes9x/win32/zlib/src/gzlib.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_gzread.o: ../snes9x/win32/zlib/src/gzread.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_gzwrite.o: ../snes9x/win32/zlib/src/gzwrite.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_infback.o: ../snes9x/win32/zlib/src/infback.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_inffast.o: ../snes9x/win32/zlib/src/inffast.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_inflate.o: ../snes9x/win32/zlib/src/inflate.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_inftrees.o: ../snes9x/win32/zlib/src/inftrees.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_trees.o: ../snes9x/win32/zlib/src/trees.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_uncompr.o: ../snes9x/win32/zlib/src/uncompr.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_zlib_src_zutil.o: ../snes9x/win32/zlib/src/zutil.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_png.o: ../snes9x/win32/libpng/src/png.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngerror.o: ../snes9x/win32/libpng/src/pngerror.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngget.o: ../snes9x/win32/libpng/src/pngget.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngmem.o: ../snes9x/win32/libpng/src/pngmem.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngpread.o: ../snes9x/win32/libpng/src/pngpread.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngread.o: ../snes9x/win32/libpng/src/pngread.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngrio.o: ../snes9x/win32/libpng/src/pngrio.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngrtran.o: ../snes9x/win32/libpng/src/pngrtran.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngrutil.o: ../snes9x/win32/libpng/src/pngrutil.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngset.o: ../snes9x/win32/libpng/src/pngset.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngtrans.o: ../snes9x/win32/libpng/src/pngtrans.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngwio.o: ../snes9x/win32/libpng/src/pngwio.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngwrite.o: ../snes9x/win32/libpng/src/pngwrite.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngwtran.o: ../snes9x/win32/libpng/src/pngwtran.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

obj/win32_libpng_src_pngwutil.o: ../snes9x/win32/libpng/src/pngwutil.c | obj
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

.PHONY: all clean

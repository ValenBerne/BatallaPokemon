# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Primer_TP.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Primer_TP.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Primer_TP.dir\flags.make

CMakeFiles\Primer_TP.dir\main.c.obj: CMakeFiles\Primer_TP.dir\flags.make
CMakeFiles\Primer_TP.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Primer_TP.dir/main.c.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Primer_TP.dir\main.c.obj /FdCMakeFiles\Primer_TP.dir\ /FS -c "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\main.c"
<<

CMakeFiles\Primer_TP.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Primer_TP.dir/main.c.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\Primer_TP.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\main.c"
<<

CMakeFiles\Primer_TP.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Primer_TP.dir/main.c.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Primer_TP.dir\main.c.s /c "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\main.c"
<<

CMakeFiles\Primer_TP.dir\batallas.c.obj: CMakeFiles\Primer_TP.dir\flags.make
CMakeFiles\Primer_TP.dir\batallas.c.obj: ..\batallas.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Primer_TP.dir/batallas.c.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Primer_TP.dir\batallas.c.obj /FdCMakeFiles\Primer_TP.dir\ /FS -c "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\batallas.c"
<<

CMakeFiles\Primer_TP.dir\batallas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Primer_TP.dir/batallas.c.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\Primer_TP.dir\batallas.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\batallas.c"
<<

CMakeFiles\Primer_TP.dir\batallas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Primer_TP.dir/batallas.c.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Primer_TP.dir\batallas.c.s /c "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\batallas.c"
<<

# Object files for target Primer_TP
Primer_TP_OBJECTS = \
"CMakeFiles\Primer_TP.dir\main.c.obj" \
"CMakeFiles\Primer_TP.dir\batallas.c.obj"

# External object files for target Primer_TP
Primer_TP_EXTERNAL_OBJECTS =

Primer_TP.exe: CMakeFiles\Primer_TP.dir\main.c.obj
Primer_TP.exe: CMakeFiles\Primer_TP.dir\batallas.c.obj
Primer_TP.exe: CMakeFiles\Primer_TP.dir\build.make
Primer_TP.exe: CMakeFiles\Primer_TP.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Primer_TP.exe"
	"C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Primer_TP.dir --rc="C:\PROGRA~2\Windows Kits\8.1\bin\x86\rc.exe" --mt="C:\PROGRA~2\Windows Kits\8.1\bin\x86\mt.exe" --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\Primer_TP.dir\objects1.rsp @<<
 /out:Primer_TP.exe /implib:Primer_TP.lib /pdb:"C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\cmake-build-debug\Primer_TP.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Primer_TP.dir\build: Primer_TP.exe

.PHONY : CMakeFiles\Primer_TP.dir\build

CMakeFiles\Primer_TP.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Primer_TP.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Primer_TP.dir\clean

CMakeFiles\Primer_TP.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP" "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP" "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\cmake-build-debug" "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\cmake-build-debug" "C:\Users\valentin.berne\Desktop\2020 Primer Cuatrimestre\Primer TP\cmake-build-debug\CMakeFiles\Primer_TP.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Primer_TP.dir\depend


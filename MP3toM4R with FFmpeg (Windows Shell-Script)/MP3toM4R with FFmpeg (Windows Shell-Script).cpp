// MP3toM4R with FFmpeg
// Version 1

// The paths still have to be set manually!

@echo off
setlocal enabledelayedexpansion
for%% a in("*.mp3") do (
    ffmpeg - ss 0 - t 30 - i "%%a" - acodec aac - b:a 128k - f adts - map_metadata - 1 - vn "V:\Convert\bin\m4r_files_temp\%%~na.m4a"
    ffmpeg - i "V:\Convert\bin\m4r_files_temp\%%~na.m4a" - acodec copy - t 29 - f adts - map_metadata - 1 - vn "V:\Convert\bin\m4r_files\%%~na.m4r"
    del "V:\Convert\bin\m4r_files_temp\%%~na.m4a"
    )
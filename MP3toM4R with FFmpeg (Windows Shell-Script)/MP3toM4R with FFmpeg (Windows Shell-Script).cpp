// MP3toM4R with FFmpeg
// Version 2

@echo off
set / p output_folder = Please enter the folder path where the converted files should be saved :

if not exist "%output_folder%" (
    echo The folder % output_folder % does not exist.The script will terminate.
    pause
    exit
    )

    for%% a in("*.mp3") do (
        ffmpeg - ss 0 - t 30 - i "%%a" - acodec aac - b:a 128k - f adts - map_metadata - 1 - vn "%output_folder%\%%~na.m4a"
        ffmpeg - i "%output_folder%\%%~na.m4a" - acodec copy - t 29 - f adts - map_metadata - 1 - vn "%output_folder%\%%~na.m4r"
        del "%output_folder%\%%~na.m4a"
        )

        echo Conversion completed.
        pause

/c/gource/gource.exe --user-image-dir ./devs_images/ -1280x720 -font-size 24 -seconds-per-day 5 -key -date-format "%A, %b %d %I:%M%p %Z" -title "Fury Progress as of $(date +%x)" -o temp.ppm 
/c/ffmpeg_windows/ffmpeg.exe -y -r 60 -f image2pipe -vcodec ppm -i temp.ppm -vcodec libx264 -preset ultrafast -pix_fmt yuv420p -crf 1 -threads 0 -bf 0 gource.mp4
rm -f temp.ppm

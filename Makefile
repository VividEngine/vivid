vivid.exe: src/main.c
	gcc "src/main.c" "src/icon.res" -I"C:/Users/josha/Coding/C/SDL3/x86_64-w64-mingw32/include" -L"C:/Users/josha/Coding/C/SDL3/x86_64-w64-mingw32/lib" -lSDL3 -mwindows -o "bin/vivid.exe" -I"C:/Users/josha/Coding/C/SDL3_image/x86_64-w64-mingw32/include" -L"C:/Users/josha/Coding/C/SDL3_image/x86_64-w64-mingw32/lib" -lSDL3_image -I"C:/Users/josha/Coding/C/SDL3_ttf/x86_64-w64-mingw32/include" -L"C:/Users/josha/Coding/C/SDL3_ttf/x86_64-w64-mingw32/lib" -lSDL3_ttf
	cp "C:\Users\josha\Coding\C\SDL3\x86_64-w64-mingw32\bin\SDL3.dll" ./bin
	cp "C:\Users\josha\Coding\C\SDL3_image\x86_64-w64-mingw32\bin\SDL3_image.dll" ./bin
	cp "C:/Users/josha/Coding/C/SDL3_ttf/x86_64-w64-mingw32/bin/SDL3_ttf.dll" ./bin
	cp ./src/icon_tr.png ./bin
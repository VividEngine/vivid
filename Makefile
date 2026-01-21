vivid.exe: src/main.c
	mkdir -p bin
	gcc "src/main.c" "src/icon.res" -I"./src/SDL3/x86_64-w64-mingw32/include" -L"./src/SDL3/x86_64-w64-mingw32/lib" -lSDL3 -mwindows -o "bin/vivid.exe" -I"./src/SDL3_image/x86_64-w64-mingw32/include" -L"./src/SDL3_image/x86_64-w64-mingw32/lib" -lSDL3_image -I"./src/SDL3_ttf/x86_64-w64-mingw32/include" -L"./src/SDL3_ttf/x86_64-w64-mingw32/lib" -lSDL3_ttf
	cp "./src/SDL3/x86_64-w64-mingw32/bin/SDL3.dll" ./bin
	cp "./src/SDL3_image/x86_64-w64-mingw32/bin/SDL3_image.dll" ./bin
	cp "./src/SDL3_ttf/x86_64-w64-mingw32/bin/SDL3_ttf.dll" ./bin
	cp ./src/icon_tr.png ./bin
	cp ./src/*.ttf ./bin
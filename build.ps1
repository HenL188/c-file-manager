if (Test-Path main.exe){
    del main.exe
}
cc main.c -o main -L. -l:utilslib.a
./main.exe

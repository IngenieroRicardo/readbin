package main

import (
        "fmt"
        "log"
        "os"
        "unicode"
)

func main(){
    if len(os.Args) == 1 {
        return
    }
    fmt.Print("\nINICIA EL ANALISIS...\n\n");
    file, err := os.Open(os.Args[1])
    if err != nil {
        log.Fatal(err)
    }
    fi, err := file.Stat()
    if err != nil {
        log.Fatal(err)
    }
    data := make([]byte, fi.Size())
    count, err := file.Read(data)
    if err != nil {
        log.Fatal(err)
    }
    for i := 0; i < count; i++ {
	fmt.Print("Bin[",i,"]=",fmt.Sprintf("%08b", data[i]))
	fmt.Print("  Hex[",i,"]=",fmt.Sprintf("0x%02x", data[i]))
	fmt.Print("  ASCII[",i,"]=",fmt.Sprintf("%v", data[i]))
    	if ( data[i] != 144 && data[i] != 152 ){    	
        	fmt.Print("\tChar[",i,"]=",fmt.Sprintf("%c", data[i]),"\n")
        } else {
        	fmt.Print("\tChar[",i,"]= \n")
        }
    }
    fmt.Print("\n\nSTRING: \n\n");
    for i := 0; i < count; i++ {
        if ( data[i] != 0 ){
            if unicode.IsDigit(rune(data[i])) || unicode.IsLetter(rune(data[i])) || unicode.IsSymbol(rune(data[i]))  {
                fmt.Print(fmt.Sprintf("%c", data[i]))
            } else {
                fmt.Print(" ")
            }
        }
    }
    file.Close()
    fmt.Print("\n\nFIN DEL ANALISIS...\n\n");
}


# What does this do?
This project contains `C/C++` function templates to write cheat codes in a higher level language. The assembly then can be viewed with a disassembler like [`IDA Pro`](https://www.hex-rays.com/products/ida/). The machine code can be copied with [`ELF Function Utility`](https://github.com/BullyWiiPlaza/ELF-Function-Utility). The machine code then has to be placed into an [execute assembly](http://cosmocortney.ddns.net/enzy/cafe_code_types_en.php#asm) cheat code and sent using [`JGecko U`](https://github.com/BullyWiiPlaza/JGeckoU).<br/><br/>
This project does **NOT** aim to compile into a working Wii U home brew app. It is only meant for generating assembly for use with cheat codes, so do **NOT** put the `ELF` file onto your SD card as you usually would.

# Is there a complete tutorial?
Yes, [this](https://www.youtube.com/watch?v=Eh41pZ1LwGQ) video.

# How do I compile?
Just like described [here](https://github.com/dimok789/homebrew_launcher/blob/master/README.md#building-the-homebrew-launcher) but without `portlibs`.

# Credits
**dimok** for `link.ld` and `Makefile`<br/>
**BullyWiiPlaza** for template functions
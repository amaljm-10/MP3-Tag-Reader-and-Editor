# MP3-Tag-Reader-and-Editor
A C-based command-line tool to read and edit ID3v2 metadata tags in MP3 files using binary file I/O.
# 🎵 MP3 Tag Reader & Editor

A command-line application written in **C** to read and edit **ID3v2 metadata tags** in MP3 files. The project demonstrates low-level binary file handling by parsing and modifying MP3 metadata directly without affecting the audio content.

## 🚀 Features

- View MP3 metadata tags
- Edit Title, Artist, Album, Year, Genre, and Comment
- Direct binary file manipulation using C
- In-place metadata editing (no temporary files)
- ID3v2 header validation
- Modular source code for easy maintenance

## 🛠️ Technologies Used

- C Programming
- GCC Compiler
- Linux
- File Handling (`fopen`, `fread`, `fwrite`, `fseek`)
- ID3v2 Metadata Protocol

## 📂 Project Structure

```
├── main.c          # Entry point
├── view.c          # View metadata
├── edit.c          # Edit metadata
├── help.c          # Help menu
├── mp3reader.h     # Header file
└── Makefile        # Build instructions (if available)
```

## 📌 Supported Tags

| Frame ID | Description |
|----------|-------------|
| TIT2 | Title |
| TPE1 | Artist |
| TALB | Album |
| TYER | Year |
| TCON | Genre |
| COMM | Comment |

## 💻 Usage

### Compile

```bash
gcc *.c -o mp3tag
```

### View Metadata

```bash
./mp3tag -v sample.mp3
```

### Edit Title

```bash
./mp3tag -e -t "New Title" sample.mp3
```

### Edit Artist

```bash
./mp3tag -e -a "Artist Name" sample.mp3
```

### Edit Album

```bash
./mp3tag -e -A "Album Name" sample.mp3
```

### Edit Year

```bash
./mp3tag -e -y 2025 sample.mp3
```

### Help

```bash
./mp3tag -help
```

## 📖 Learning Outcomes

- Binary file parsing
- File pointer manipulation
- ID3v2 frame structure
- Modular programming in C
- Command-line application development

## 🎯 Future Improvements

- Support ID3v2.4
- Add album artwork editing
- Batch editing of multiple MP3 files
- UTF-8 metadata support
- Cross-platform compatibility

## 👨‍💻 Author

**Amal John Mathew**

If you found this project helpful, consider giving it a ⭐ on GitHub!

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#pragma GCC optimize("Ofast")

constexpr int inf = 1 << 30;
constexpr int maxBufferSize = (1 << 23) | (1 << 22);
// constexpr int maxBufferSize = 14;
char buffer[maxBufferSize];
int x, max = -inf;

struct FileReader {
	FileReader(const FileReader& fr) {}
	int bufferSize, bufferPointer;
	int fileNo = 0;
	inline void loadBuffer() {
		bufferSize = read(fileNo, buffer, maxBufferSize);
		bufferPointer = 0;
	}
	inline char nextChar() {
		if (bufferPointer >= bufferSize)
			loadBuffer();
		return buffer[bufferPointer++];
	}
	inline bool skipSpaces() {
		char c;
		while (((c = nextChar()) == ' ' || c == '\n') && c != '\0');
		if (c == '\0')
			return 0;
		bufferPointer--;
		return 1;
	}
	FileReader() {
		fileNo = 0;
		loadBuffer();
	}
	FileReader(int _fileNo) {
		fileNo = _fileNo;
		loadBuffer();
	}
	~FileReader() {
		close(fileNo);
	}
	inline int readInt() {
		int n = 0, mul = 1;
		char c;
		c = nextChar();
		if (c == '-') mul = -1;
		else bufferPointer--;
		do {
			c = nextChar();
			if (c >= '0')
				n = n*10 + (c-'0');
		} while (c >= '0');
		return n * mul;
	}
	void skip(int i) {
		while (i--) loadBuffer();
	}
};

int min(int a, int b) {
	return a < b ? a : b;
}

signed main() {
	FileReader fr;
	int n = fr.readInt();
	int skip = 1;
	fr.skip(skip);
	for (int i = 0; i < min(maxBufferSize, n - skip*maxBufferSize); i++) {
		x = fr.readInt();
		if (x > max) max = x;
	}
	if (max == -inf) {
		return 9;
	}
	printf("%i", max);
	return 0;
}


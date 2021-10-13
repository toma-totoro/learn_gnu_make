vpath %.c src
vpath %.l src
vpath %.h include

CPPFLAGS = -I include

count_words: count_words.o counter.o lexer.o -lfl
	gcc $(CPPFLAGS) $^ -o$@

count_words.o: count_words.c counter.h
	gcc -c $(CPPFLAGS) $<

counter.o: counter.c counter.h lexer.h
	gcc -c $(CPPFLAGS) $<

# lexer.l から flexコマンドでlexer.cを生成し、lexer.oを作成する。
lexer.o: lexer.c lexer.h
	gcc -c $(CPPFLAGS) $<

lexer.c: lexer.l
	flex -t $< > $@

.PHONY: clean
clean:
	rm -f *.o lexer.c

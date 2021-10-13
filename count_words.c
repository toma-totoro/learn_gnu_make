#include <stdio.h>
#include <stdlib.h>
#include <counter.h>
// 以下のexternによる宣言は、counter.hへ移動
// extern int fee_count, fie_count, foe_count, fum_count;
// extern int yylex( void );
int main( int argc, char ** argv )
{
  // yylex()は、counter.c内のcounter関数へ移動した。
  // yylex();
  // mainから直接yylex関数を呼び出すのではなく、counter_words.c内のcounter関数経由で集計値を取得する。
  int counts[4];
  counter(counts);
  printf( "%d %d %d %d\n", counts[0], counts[1], counts[2],  counts[3]);
  // printf( "%d %d %d %d\n", fee_count, fie_count, foe_count, fum_count );

  // exit関数を使用するには、stdlibをインクルードする必要あり。
  // exit関数、returnどちらがよいかは、下記のページを参照の事。
  // https://monologu.com/which-use-return-or-exit/
  exit( 0 );
  /* return 0; */
}

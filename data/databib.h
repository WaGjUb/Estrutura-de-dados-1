typedef struct{
int d;
int m;
int y;
}Date;

Date* createDate(int d, int m, int y); //Criar uma data
int getDate(Date *date, char* str); //recuperar a data no formato brasileiro
int getAmericanDate(Date *date, char* str); //recuperar a data no formato americano
int setDate(Date *date, int d, int m, int y); //alterar a data
int getDay(Date *date); //recuperar somente o dia da data
int getMonth(Date *date); //recuperar somente o mês da data
int getWritingMonth(Date *date); //recuperar o mês da data por extenso
int getYear(Date *date); //recuperar somente o ano da data
int checkDate(Date *date); //validat uma data

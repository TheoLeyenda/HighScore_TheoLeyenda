#include "../HighScoreLibrary/HighScoreLibrary/HighScore.h"
using namespace HighScoreListLT;

void main()
{
	cout << "Prueba de Libreria por Defecto:" << endl<<endl;

	HighScore* highScorePorDefecto = new HighScore(true,0); //constructor con dos parametros booleano para determinar si generar la lista highScore por defecto o no y el tamaño de la lista
															//como vamos a generar la lista por defecto y esta tiene un tamaño inicial que se define internamente ponemos la variable 0.

	cout << "Lista por defecto:" << endl;
	for(int i = 0; i < highScorePorDefecto->GetSizeListHighScore(); /*devuelve el tamaño de la lista*/ i++)
	{
		cout << highScorePorDefecto->GetNodeScore(i).name.c_str() << "  " << highScorePorDefecto->GetNodeScore(i).score<< endl; // devuelve el nodo que contiene el puntaje y el nombre guardado.
	}

	highScorePorDefecto->ClearListHighScore(); //Limpia La Lista de HighScore.
	cin.get();
	//cin.get();
	fflush(stdin);
	system("cls");

	cout << "Prueba de Libreria Personalizada:" << endl<<endl;

	HighScore* highScore = new HighScore(false, 5); //en este caso creamos una lista personalizada de tamaño inicial 5.
	float scorePlayer;
	string namePlayer;
	cout << "Inicialice su lista" << endl;
	
	cout << "Tamanio Lista: "<< highScore->GetSizeListHighScore() << endl;
	for(int i = 0; i < highScore->GetSizeListHighScore(); i++)
	{
		fflush(stdin);
		cout << "Nombre: ";
		getline(cin, namePlayer);
		cout << "Puntaje: ";
		cin>> scorePlayer;
		cin.get();

		highScore->InsertScore(scorePlayer, namePlayer);
	}
	cout << endl << "Mostrando los Datos Ingresados:" << endl;
	for (int i = 0; i < highScore->GetSizeListHighScore();i++)
	{
		cout << highScore->GetNodeScore(i).name.c_str() << "  " << highScore->GetNodeScore(i).score << endl;
	}
	delete highScore;
	delete highScorePorDefecto;
}
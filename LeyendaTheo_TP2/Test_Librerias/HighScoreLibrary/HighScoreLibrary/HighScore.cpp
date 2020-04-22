#include "HighScore.h"
using namespace HighScoreListLT;

HighScore::HighScore(bool _defaultList, int _sizeList)
{
	ListScores = new list<NodeScore>();
	if(_defaultList)
	{
		sizeList = 15;
		string names[] = { "Betito Fernandez", "Diego Armando Maradona", "La Cristi", "Nico Del Caño", "Rogelio Mendez", "La Galera", "Biondini", "Jorge Rafael Videla", "Sao es malisima", "Coraje el Perro Cobarde","Edd","Edd","Eddy","Dexter el niño genio","TL"};
		int puntajes[] = { 99999999,				100000,						10000,					9500,			 9000,      8500    ,         8000,                 7500,               7000,             6500, 6500, 6000,         3000,           1500, 500 };
		
		for(int i = 0; i < sizeList; i++)
		{
			NodeScore nodeScore;
			nodeScore.score = puntajes[i];
			nodeScore.name = names[i].c_str();
			ListScores->push_back(nodeScore);
		}
	}
	else
	{
		sizeList = _sizeList;
	}
}
int HighScore::InsertScore(int _score, string _name)
{
	NodeScore nodeScore;
	nodeScore.name = _name.c_str();
	nodeScore.score = _score;
	list<NodeScore>::iterator iterB;
	list<NodeScore>::iterator iterE;
	list<NodeScore>::iterator nextIter;
	list<NodeScore>::iterator iter;
	iterB = ListScores->begin();
	iterE = ListScores->end();
	nextIter = ListScores->begin();
	int size = ListScores->size();
	if (size > 0)
	{
		nextIter++;
		for (iter = iterB; iter != iterE; iter++)
		{
			
			if(size < sizeList && nextIter == iterE && nodeScore.score < iter->score)
			{
				ListScores->push_back(nodeScore);
				return 0;
			}
			else if (nodeScore.score >= iter->score)
			{
				ListScores->insert(iter, nodeScore);
				if (size > sizeList )
				{
					//ListScores->remove(ListScores->back());
					ListScores->pop_back();
				}
				return 0;
			}

			if (nextIter != iterE) 
			{
				nextIter++;
			}
		}
	}
	else
	{
		ListScores->push_back(nodeScore);
		return 0;
	}
	return 0;
}
int HighScore::GetSizeListHighScore()
{
	return sizeList;
}
NodeScore HighScore::GetNodeScore(int indexScore)
{
	int size = ListScores->size();
	list<NodeScore>::iterator iter;
	if (indexScore < size)
	{
		iter = ListScores->begin();
		for (int i = 0; i < indexScore; i++)
		{
			if (iter != ListScores->end()) 
			{
				iter++;
			}
			else 
			{
				cout << "Error: El puntero iter sobrepasa el ultimo bloque de memoria de la lista (ListScores->end)" << endl;
				return *iter;
			}
		}
		return *iter;
	}
	else
	{
		cout << "Error: El numero ingresado Exede los limites de la lista." << endl;
		return *iter;
	}

}
int HighScore::GetSizeInternalListHighScore()
{
	int size = ListScores->size();
	return size;
}
void HighScore::ClearListHighScore()
{
	ListScores->clear();
}
HighScore::~HighScore()
{
	delete ListScores;
}
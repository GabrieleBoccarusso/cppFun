#include <iostream>

using namespace std;

struct tipo_elemento 
{
  int dato;
};

struct tipo_nodo
{
  tipo_elemento info;
  tipo_nodo * left;
  tipo_nodo * right;
};

struct tipo_albero_binario 
{
  tipo_nodo * root;
};

void crea_albero (tipo_albero_binario &t);
bool albero_vuoto (tipo_albero_binario &t);
bool inserimento_albero (tipo_albero_binario &t, tipo_elemento e);
void ins_ricorsivo_albero (tipo_nodo * &ptr, tipo_nodo *n);
void ins_elemento(tipo_elemento &e);
void vis_albero(tipo_nodo * ptr);
void vis_elemento(tipo_elemento e);
void ricerca_albero_binario (tipo_nodo * radice, int numero);

int main() 
{
  char scelta;
  tipo_elemento e;
  tipo_albero_binario t;
  crea_albero(t);
  int numero;

  do
  {
    cout << "0 - uscita\n";
    cout << "1 - inserimento\n";
    cout << "2 - ricerca\n";
    cout << "> ";
    cin >> scelta;

    switch (scelta)
    {
      case '1': // inserimento
        ins_elemento (e);
        if (inserimento_albero(t, e))
          cout << "riuscito\n";
        else 
          cout << "non riuscito";
        break;
      case '2':
        cout << "inserisci numero da cercare: ";
        cin >> numero;
        ricerca_albero_binario(t.root, numero);
        break;
    }

  }while(scelta != 0);

}

void crea_albero (tipo_albero_binario &t)
{
  t.root = NULL;
}

bool albero_vuoto (tipo_albero_binario &t)
{
  bool ris = false;

  if (t.root == NULL)
    ris = true;

  return ris;
}

bool inserimento_albero (tipo_albero_binario &t, tipo_elemento e)
{
  bool ris = false;
  tipo_nodo * n;
  n=new tipo_nodo;

  if (n != NULL)
  {
    n -> info=e;
    n -> left = NULL;
    n -> right = NULL;
    ins_ricorsivo_albero (t.root, n); 
    ris = true;
  }
  return ris;
}

void ins_ricorsivo_albero (tipo_nodo * &ptr, tipo_nodo * n)
{
  if (ptr == NULL)
    ptr = n;
  else
  {
    if ((ptr -> info.dato)>(n -> info.dato))
     ins_ricorsivo_albero(ptr -> left, n);
    else 
      ins_ricorsivo_albero (ptr -> right, n);
  }

  return;
}

void ricerca_albero_binario (tipo_nodo * radice, int numero)
{
  if (!radice)
   cout << "numero non trovato\n";
  if (radice -> info.dato == numero)
    cout << "numero trovato: " << radice -> info.dato;
  else if (radice -> info.dato > numero)
    ricerca_albero_binario(radice -> left, numero);
  else
    ricerca_albero_binario(radice -> right, numero);

  return;
}

void ins_elemento(tipo_elemento &e)
{
  cout<<"Inserisci numero: "<<endl;
  cin>>e.dato;
  return;
}

void vis_elemento(tipo_elemento e)
{
  cout<<"Numero: "<<e.dato<<endl;
  return;
}
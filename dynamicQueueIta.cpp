#include <iostream>
using namespace std;

struct tipo_elemento {
  int dato;
};

struct tipo_nodo {
  tipo_elemento info;
  tipo_nodo * next;
};

struct tipo_coda
{
	tipo_nodo *cima;
   tipo_nodo *fondo;
};


void crea_coda(tipo_coda& c);
bool codavuota(tipo_coda c);
bool incoda(tipo_coda& c, tipo_elemento e);
void inselemento(tipo_elemento &e);
bool scoda(tipo_coda &c, tipo_elemento &e);
bool viscoda(tipo_coda c);
void viselemento(tipo_elemento e);

int main () 
{
  tipo_coda queue;
  char scelta;
  tipo_elemento e;
  crea_coda (queue);

  do
  {
    cout << "0 - uscita\n";
    cout << "1 - inserimento elemento\n";
    cout << "2 - estrazione elemento\n";
    cout << "3 - visualizza coda\n";
    cout << "inserisci la tua scelta: ";
    cin >> scelta;

    switch (scelta)
    {
      case '0': // uscita
        cout << "ciao\n";
        break;
      case '1':
        {
          inselemento(e);
          if (incoda (queue, e))
            cout << "elemento inserito\n";
          else
            cout << "l'elemento non può essere inserito";
        }
        break;
      case '2':
        if(!(scoda(queue,e)))
          cout << "coda vuota\n";
        else 
          cout << "estratto con successo\n";
        break;
      case '3':
        if(codavuota(queue))
          cout << "coda vuota\n";
        else
          viscoda(queue);
        break;
    }
  } while (scelta != '0');
  
  return 0;
}

void crea_coda(tipo_coda& c)
{
	c.cima=NULL;
  c.fondo=NULL;
	return;
}

bool codavuota(tipo_coda c)
{
  bool ris=false;

  if (c.cima == NULL)
  {
    ris=true;
  }
  return ris;
}

bool incoda(tipo_coda& c, tipo_elemento e)
{   
  bool ris=false;
  tipo_nodo * n;
  n = new (tipo_nodo);
  if (n != NULL)
  {
    ris = true;
    n -> info=e;
    n -> next=NULL;
    if (!(codavuota(c)))
      c.fondo -> next=n;
    else 
      c.cima = n;

    c.fondo = n;
  }

  return ris;
}

void inselemento(tipo_elemento &e)
{
  cout<< "inserisci il numero: ";
  cin>> e.dato;
  return;
}

bool scoda(tipo_coda &c, tipo_elemento &e)
{    
  bool ris = false;
  tipo_nodo * n;

  if (!(codavuota(c)))
  {
    ris = true;
    e = c.cima->info;
    n = c.cima;
    c.cima = c.cima->next;
    if (c.cima == NULL)
      c.fondo = NULL;

    delete(n);
  }
  return ris;
}

bool viscoda(tipo_coda c)
{    
  bool ris = false;
  tipo_nodo * ptr;
  if (!(codavuota(c)))
  {
    ris = true;
    ptr = c.cima;
    while (ptr != NULL)
    {
      viselemento(ptr->info);
      ptr=ptr->next;
    }
  }

  return ris;
}

void viselemento(tipo_elemento e)
{
  cout << e.dato <<endl;
  return;
}
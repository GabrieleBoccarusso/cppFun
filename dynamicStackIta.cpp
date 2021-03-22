#include <iostream>
using namespace std;

struct tipo_elemento {
  int dato;
};

struct tipo_nodo {
  tipo_elemento info;
  tipo_nodo * next;
};

struct tipo_stack {
  tipo_nodo * testa;
};

void crea_stack (tipo_stack &s);
bool stack_vuoto (tipo_stack s);
void viselemento(tipo_elemento e);
bool push (tipo_stack &s, tipo_elemento e);
bool stackvuoto(tipo_stack s);
bool pop (tipo_stack& s, tipo_elemento &e);
bool visstack (tipo_stack s);
void inselemento(tipo_elemento &e);

int main () 
{
  tipo_stack s;
  char scelta;
  tipo_elemento e;
  crea_stack(s);

  do
  {
    cout << "0 - uscita\n";
    cout << "1 - inserimento elemento\n";
    cout << "2 - estrazione elemento\n";
    cout << "3 - visualizza stack\n";
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
          if (push (s, e))
            cout << "elemento inserito\n";
          else
            cout << "l'elemento non può essere inserito\n";
        }
        break;
      case '2':
        if(!(pop(s,e)))
          cout << "stack vuoto\n";
        else 
          cout << "estratto con successo\n";
        break;
      case '3':
        if(stack_vuoto(s))
          cout << "stack vuoto\n";
        else
          visstack(s);
        break;
    }
  } while (scelta != '0');
  
  return 0;
}

void crea_stack (tipo_stack &s)
{
  s.testa = NULL;
  return;
}

bool stack_vuoto (tipo_stack s)
{
  bool ris = false;
  if (s.testa == NULL)
    ris = true;

  return ris;
}

void viselemento(tipo_elemento e)
{
  cout << e.dato <<endl;
  return;
}

bool push (tipo_stack &s, tipo_elemento e)
{
  bool ris = false;
  tipo_nodo * n;

  n = new(tipo_nodo);

  if (n != NULL)
  {
    ris = true;
    n -> info = e;
    n -> next = s.testa;

    s.testa = n;
  }

  return ris;
}

bool stackvuoto(tipo_stack s)
{
    bool ris=false;
    if(s.testa==0)
    {
        ris=true;
    }
    return ris;
}

bool pop (tipo_stack& s, tipo_elemento &e)
{
  bool ris = false;
  tipo_nodo * n;

  if (!(stackvuoto(s)))
  {
    ris = true;
    e = s.testa -> info;
    n = s.testa;
    s.testa = s.testa -> next;

    delete (n);
  }

  return ris;
}

bool visstack (tipo_stack s)
{
  bool ris = false;
  tipo_nodo*ptr;

  if (!(stackvuoto(s)))
  {
    ris = true;
    cout << "nello stack abbiamo:\n";
    ptr = s.testa;
    while (ptr != NULL)
    {
      viselemento(ptr -> info);
      ptr = ptr -> next;
    }
  }

  return ris;
}

void inselemento(tipo_elemento &e)
{
  cout<< "inserisci il numero: ";
  cin>> e.dato;
  return;
}
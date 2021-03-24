/*
different version of the dynamic list with 
a shallow research in it
03.24.2021 - mm/dd/yyy
*/
#include <iostream>
using namespace std;

struct tipo_elemento
{
  string nome_candidato;
  int voto;
};

struct tipo_nodo
{
    tipo_elemento info;
    tipo_nodo * next;
};

struct tipo_lista
{
  tipo_nodo * testa;
};

bool insListaOrdinata(tipo_lista &l, tipo_elemento e);
bool listaVuota(tipo_lista l);
void creaLista (tipo_lista &l);
void viselemento(tipo_elemento e);
void inselemento(tipo_elemento &e);
bool est_lista_ordinaria(tipo_lista &l, tipo_elemento &e);
bool visLista(tipo_lista l);
bool ricercaNome(tipo_lista l, string nome);

int main () 
{
  tipo_lista lista;
  char scelta;
  tipo_elemento e;
  creaLista (lista);
  string nome;

  do
  {
    cout << "0 - uscita\n";
    cout << "1 - inserimento elemento\n";
    cout << "2 - estrazione elemento\n";
    cout << "3 - visualizza lista\n";
    cout << "4 - cerca nome\n";
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
          if (insListaOrdinata (lista, e))
            cout << "elemento inserito\n";
          else
            cout << "l'elemento non può essere inserito";
        }
        break;
      case '2':
        if(!(est_lista_ordinaria(lista,e)))
          cout << "lista vuota\n";
        else 
          cout << "estratto con successo\n";
        break;
      case '3':
        if(listaVuota(lista))
          cout << "lista vuota\n";
        else
          visLista(lista);
        break;
      case '4':
        cout << "inserisci il nome: ";
        cin >> nome;
        if(!ricercaNome(lista, nome))
          cout << "nome non trovato\n";
        break;
    }
  } while (scelta != '0');
  
  return 0;
}

void creaLista (tipo_lista &l)
{
  l.testa = NULL;
  return;
}

bool listaVuota(tipo_lista l)
{
  bool ris = false;
  if (l.testa == NULL)
  {
    ris = true;
  }

  return ris;
}

bool insListaOrdinata(tipo_lista &l, tipo_elemento e)
{
  bool ris = false;
  tipo_nodo * n, * ptr, * prec;
  bool postrovata = false;

  n = new(tipo_nodo);

  if (n != NULL)
  {   
    ris = true;
    n -> info = e;
    ptr = l.testa;
    while ((ptr != NULL) && (!postrovata))
    {
      if (ptr -> info.nome_candidato < e.nome_candidato)
      { 
        prec = ptr;
        ptr = ptr -> next;
      }
      else
        postrovata = true;
    } 
    
    n -> next = ptr;

    if (ptr != l.testa)
      prec -> next = n;
    else
      l.testa=n;
  }
  return ris;
}

void viselemento(tipo_elemento e)
{
  cout << "nome: " << e.nome_candidato <<endl;
  cout << "voto: " << e.voto << endl;
  return;
}

void inselemento(tipo_elemento &e)
{
  cout<< "inserisci il nome: ";
  cin>> e.nome_candidato;
  cout << "inserisci il voto: ";
  cin>> e.voto;
  return;
}

bool visLista(tipo_lista l)
{
    bool ris=false;
    tipo_nodo *ptr;

    if(!(listaVuota(l)))
    {
        ris=true;
        cout<<"la lista contiene"<<endl;
        ptr=l.testa;
        while(ptr!=NULL)
        {
            viselemento(ptr->info);
            ptr = ptr -> next;
        }
    }
    cout<<endl<<endl;
    return ris;
}

bool est_lista_ordinaria(tipo_lista &l, tipo_elemento &e)
{
  bool ris = false;
  tipo_nodo * ptr, * prec;
  if(listaVuota(l))
    cout<<"La lista e' vuota"<<endl;
  else
  {
    prec = l.testa;
    ptr = l.testa;
    while((ptr != NULL) && (!ris))
    {
      if(ptr -> info.nome_candidato == e.nome_candidato)
      {
        ris = true;
        cout<<"elemento trovato\n";
        e = ptr -> info;
        if(ptr == l.testa)
          l.testa=ptr->next;
        else
          prec->next=ptr->next;
        delete (ptr);
      }
      else if(ptr -> info.nome_candidato > e.nome_candidato)
        ptr=NULL;
      else
      {
        prec=ptr;
        ptr=ptr->next;
      }
    }
    if(!ris)
    cout<<"elemento non trovato\n";
  }
  return ris;
}

bool ricercaNome(tipo_lista l, string nome)
{
  bool ris = false;
  tipo_nodo *ptr;

  if(!(listaVuota(l)))
  {
    ptr = l.testa;
    while(ptr != NULL)
    {
      if (ptr -> info.nome_candidato == nome)
      {
        ris = true;
        viselemento(ptr->info);
        return ris;
      }
      else
        ptr = ptr -> next;
    }
  }
  return ris;
}
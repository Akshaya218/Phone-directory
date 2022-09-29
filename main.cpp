#include <iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<conio.h>
#include <iomanip>
#include <cctype>
#include <regex>

using namespace std;
const int TABLE_SIZE=128;

struct phone
{
    char fname[50];
    char lname[50];
    long long ph_no;

    phone()
    {
        strcpy(fname," ");
        strcpy(lname," ");
        ph_no=0;
    }

    void get_data()
    {
        cout<<"\n\t\t\t--------------------------------------------------------";
        cout<<"\n\t\t\t\tFirst name  :";
        cin>>fname;
        cout<<"\n\t\t\t\tLast name   :";
        cin>>lname;
        /*while(1)
			{
				cout<<"\n\t\t\t\tPhone number:";
				cin>>ph_no;
				if(ph_no > 1000000000 || ph_no < 9999999999)
					break;
				cout<<"\nInvalid input!";
			}*/
        cout<<"\n\t\t\t\tPhone number:";
        cin>>ph_no;
        //bool isValid();
}

      /*bool isValid(long long ph)
        {

          const regex pattern("[7-9][0-9]{9}");
          if(regex_match(ph, pattern))
          {
            return true;
          }
          else
          {
            return false;
          }
        }*/

    bool operator>(const phone& s)
    {
        for(int i=0; fname[i]!='\0' && s.fname[i]!='\0';i++)
        {
            if(fname[i]<s.fname[i])
                return false;
            else if(fname[i]>s.fname[i])
                return true;
        }
        if(strlen(this->fname)>strlen(s.fname))
            return true;
        else
            return false;
    }

    bool operator <(const phone& s)
    {
        for(int i=0;fname[i]!='\0' && s.fname[i]!='\0';i++)
        {
            if(fname[i]<s.fname[i])
                return true;
            else if(fname[i]>s.fname[i])
                return false;
        }
        if(strlen(this->fname)<strlen(s.fname))
            return true;
        else
            return false;
    }

    void operator-(const phone& s)
    {
        strcpy(this->fname,s.fname);
        strcpy(this->lname,s.lname);
        this->ph_no=s.ph_no;
    }

    void display()
    {
        cout<<"\t\t\t\tFirst Name:"<<fname<<endl;
        cout<<"\t\t\t\tLast Name :"<<lname<<endl;
        cout<<"\t\t\t\tPhone Number:"<<ph_no<<endl;
    }

};

int x=-1;
phone heap[1000];

void heapConstruct(phone m)
{
    x++;
    heap[x]=m;
    int child=x;
    phone temp;
    int index=x/2;

    while(index>=0)
    {
        if(heap[index]>heap[child])
        {
            temp = heap[index];
            heap[index] = heap[child];
            heap[child] = temp;
            child = index;

            index=index/2;

        }
        else
        {
           break;
        }

    }

}

void heapSort()
{
    int left,right;
    cout<<"\n";
    while(x>=0)
    {
        phone m;
        m=heap[0];

       if(!(strlen(m.fname)==1))
           cout<<"\t\t\t"<<m.fname<<"\t\t\t\t"<<m.lname<<"\t\t\t"<<m.ph_no<<"\n";

        heap[0] = heap[x];
        x = x - 1;

        phone temp;

        int index = 0;

        int length = x;
        left = 1;

        right = left + 1;

        while (left <= length)
        {

            if (!(heap[index] > heap[left]) && !(heap[index] > heap[right]))
            {
                break;
            }
            else
            {
                if (heap[left] < heap[right])
                {
                    temp = heap[index];
                    heap[index] = heap[left];
                    heap[left] = temp;
                    index = left;
                }

                else
                {
                    temp = heap[index];
                    heap[index] = heap[right];
                    heap[right] = temp;
                    index = right;
                }
            }

            left = 2 * left;
            right = left + 1;
        }
    }
}

void sort(phone m[], int n)
{

    for (int i = 0; i < n; i++)
    {
        heapConstruct(m[i]);
    }
    heapSort();

}

struct phone p[1000];
int s=0;
int no=0;

void write(char * filename)
{
    ofstream fil(filename, ios::out | ios::binary);
    if(!fil)
    {
      cout << "File does not exist..." << endl;
    }
    fil.write(reinterpret_cast<char *>(&s), sizeof(s));
    for(int i=0;i<s;i++)
    {
        fil.write((char *) &p[i], sizeof(phone));
    }
    fil.close();
}

void read_file(char * filename)
{
    ifstream fil(filename, ios::in | ios::binary);
    if(!fil)
    {
      cout << "File does not exist..." << endl;
      return;
    }
    fil.read(reinterpret_cast<char *>(&s), sizeof(s));
    for(int i=0;i<s;i++)
    {
        fil.read((char *) &p[i], sizeof(p[i]));

    }
    fil.close();
}

struct node
{
    phone data;
    node* next;
};


class linkedList
{
    node* head;
    public:

        linkedList()
        {
            head = NULL;
        }

        bool isEmpty()
        {
            if(head==NULL)
                return true;
            return false;
        }

        void insert(phone d)
        {
            node* new_node = new node();
            new_node->data = d;
            new_node->next = head;
            head = new_node;
        }

        void display()
        {
            node* n=head;
            while (n != NULL)
                {
                    n->data.display();
                    //cout<<n->data.fname;
                    n = n->next;
                }
        }

        void search(char* t)
        {
            int st;
            node* n=head;
           while (n != NULL)
                {
                    if(strcmp(n->data.fname,t)==0)
                    {
                         n->data.display();
                         return;
                    }
                    n = n->next;
                }

            cout<<"\t\t\t\tNot found";

}

            /*int st, n1, n2;
            node* n = head;
            char name1[60], name2[60];
            n1 = sizeof(n->data.fname)/sizeof(n->data.fname[0]);
            n2 = sizeof(t)/sizeof(t[0]);
            //cout<<n1<<"\n"<<n2<<"\n"<<n<<endl;
            for(int i=0;i<n1;i++)
                {
                name1[i] = (char)tolower(n->data.fname[i]);
                }
             for(int j=0;j<n1;j++)
                {
                name2[j] = (char)tolower(t[j]);
                }

            while (n != NULL)
                {

                    if(strstr(name1,name2))
                    {
                         n->data.display();
                         return;
                    }

                    n = n->next;
                }

                cout<<"\t\t\t\tNot found";

        }
*/
         void update()
        {
            node* n=head;
            while (n != NULL)
                {
                    p[s] = n->data;
                    s++;
                    n = n->next;
                }
        }
};

class Hashmap{

    linkedList array[26];

    public:
        void insert(phone d)
        {
           array[hashcode(d.fname)].insert(d);
        }

        void find(char* d)
        {
           array[hashcode(d)].search(d);
           write("Phone.dat");
        }

        int hashcode(char* s)
        {
            if(s[0] > 90)
                return s[0]-97;
            else
                return s[0]-65;
        }


        void display()
        {
            for(int i =0 ;i<26;i++)
            {
                if(!array[i].isEmpty())
                {
                    array[i].display();
                }
            }
        }

};

void printArray(phone p[], int n)
{
    cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 60 ) << '-'<< std::setfill(' ') << std::endl;
    cout  <<"\t\t\t"<< "| " << setw(20) << left <<"FIRST NAME" << "| " << setw(10) << left << "LAST NAME"<< "| " << setw(22) << left << "PHONE NUMBER" << "| "<<endl<<"\t\t\t"<<  std::setfill( '-' )<< std::setw( 60 ) << "-" ;
    cout << std::setfill(' ');
        if(n == 0)
            cout << "\nNO CONTACTS FOUND";
    for (int i = 0; i <= n-1; i++)
    {
        if(!(strlen(p[i].fname)==1))
        cout  <<endl <<"\t\t\t"<< "| " << setw(20) << left << p[i].fname<< "| " << setw(10) << left << p[i].lname << "| "<<setw(22)<<left<<p[i].ph_no<<"|";
         //cout<<"\n"<<p[i].fname<<"\n\t\t\t\t"<<p[i].lname<<"\n\t\t\t\t"<<p[i].ph_no;
    }

    cout <<endl <<"\t\t\t"<< std::setfill( '-' ) << std::setw( 60 )<< '-' ;
    return;

}

void updateContact(char *filename,phone p[])
{
    char up[5];
    cout<<"\n\t\t\t\tEnter the contact to be updated";
    cin>>up;


}

void deleteContact(char *filename,phone p[])
{
    char del[10];
    cout<<"\n\t\t\t\tEnter the contact to be deleted:";
    cin>>del;
    ofstream fil(filename, ios::out | ios::binary);
    if(!fil)
    {
      cout << "File does not exist..." << endl;
    }
    int y=s;
    for(int i=0;i<s;i++)
    {
        if(strcmp(p[i].fname,del)==0)
        {
            y--;
        }
    }
    //fil.write(reinterpret_cast<char *>(&y), sizeof(s));
    fil.write((char *) &y,sizeof(s));
    for(int i=0;i<s;i++)
    {
        if(strcmp(p[i].fname,del)==0)
        {
            continue;   //skip
        }

        fil.write((char *) &p[i], sizeof(phone));
    }
    fil.close();

    read_file("Phone.dat");
    cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 55 ) << '-'<< std::setfill(' ') << std::endl;
    cout  <<"\t\t\t"<< "| " << setw(20) << left <<"FIRST NAME" << "| " << setw(10) << left << "LAST NAME"<< "| " << setw(20) << left << "PHONE NUMBER" << "| "<<endl<<"\t\t\t"<<  std::setfill( '-' )<< std::setw( 55 ) << "-" ;
    cout << std::setfill(' ');
   for(int i=0;i<s;i++)
   {
       if(!(strlen(p[i].fname)==1))
        cout  <<endl <<"\t\t\t"<< "| " << setw(20) << left << p[i].fname<< "| " << setw(10) << left << p[i].lname
        << "| "<<setw(20)<<left<<p[i].ph_no<<"|";
   }

   cout <<endl <<"\t\t\t"<< std::setfill( '-' ) << std::setw( 55 )<< '-' ;
}

int main()
{
    int ch;
    int num;
    int n=0;

    char d[50];
    read_file("Phone.dat");
    Hashmap HT;
    for(int i=0;i<s;i++)
    {
        HT.insert(p[i]);
    }
    //system("pause");
    do
    {
        system("cls");

cout<<"\n\t\t\t\t\t    _______________";
cout<<"\n\t\t\t\t\t   /               \       ";
cout<<"\n\t\t\t\t\t  |   .---------.   |@     ";
cout<<"\n\t\t\t\t\t  '---' .-----. '---'@     ";
cout<<"\n\t\t\t\t\t    .' /6 5_4 3\ '.  @     ";
cout<<"\n\t\t\t\t\t    | |7 /...\ 2| |  @     ";
cout<<"\n\t\t\t\t\t    | |8 \___/ 1| |  @     ";
cout<<"\n\t\t\t\t\t    |   \_9_0_)\/  |  @@    ";
cout<<"\n\t\t\t\t\t /==|____________|@@@@    ";
cout<<"\n\t\t\t\t\t H-------------------@@    ";
cout<<"\n\t\t\t\t\t H   )  ||   ||  (   @@    ";
cout<<"\n\t\t\t\t\t H  /   ||   ||   \   @    ";
cout<<"\n\t\t\t\t\t H |----''---''----|       ";
cout<<"\n\t\t\t\t\t=/ |_______________|       \n";
        cout <<endl <<"\t\t\t"<<  std::setfill( '\xdb' ) << std::setw( 55 ) << '\xdb'<< std::setfill(' ') << std::endl;
        cout<<"\n                                          PHONEBOOK MANAGEMENT\n";
        cout <<endl <<"\t\t\t"<<  std::setfill( '\xdb' ) << std::setw( 55 ) << '\xdb'<< std::setfill(' ') << std::endl;
        cout<<"\n\t\t\t\t1--> INSERT\n\t\t\t\t2--> UPDATE\n\t\t\t\t3--> DELETE\n\t\t\t\t4--> SEARCH\n\t\t\t\t5--> DISPLAY\n\t\t\t\t6--> EXIT\n\n\t\t\t\tENTER YOUR CHOICE: ";
        cin>>ch;
        switch(ch)
        {

            case 1 :
                n=0;
                {
                    cout<<"\n\t\t\t\tNo of contacts to be inserted:";
                    cin>>num;
                    for(;n<num;n++)
                    {
                        p[s].get_data();
                        s++;

                    }
                    n = sizeof(p) / sizeof(p[0]);
                    printArray(p, n);
                   // system("cls");
                    write("Phone.dat");
                    //fflush(stdin);
                    getch();
                }
                break;
            case 2 :
               // modify("Phone.dat",pdt);
                break;
            case 3 :
                {
                    deleteContact("Phone.dat",p);
                }
                break;

            case 4:

               int cn;
                do
                {
                    cout<<"\n\t\t\t\tEnter the Contact name to be searched -  ";
                    cin>>d;
                    HT.find(d);
                    cout<<"\n\t\t\t\tPress 1 to continue else 0 - ";
                    cin>>cn;
                }while(cn==1);
                break;
            case 5:
                 {
                    cout<<"\n\t\t\tContact list after sorting\n";
                    cout<<"\t\t\t---------------------------\n";
                    sort(p, s);
                }
                break;

            case 6:
                {
                    write("Phone.dat");
                    break;
                }
            default :
                 printf("\n\nEnter a valid choice...\n\n");
        }
        cout<<"\n";
        system("pause");

    }while(ch!=7);

    return 0;
}

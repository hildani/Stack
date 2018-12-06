#include <iostream>
#include <conio.h>
using namespace std;

class Simpul
{
	public:
		double dData;
		string nama;
		string posisi;
			
			Simpul*pBrktnya;
			Simpul(double dd, string n, string pos): dData(dd), nama(n), posisi(pos) ,pBrktnya(NULL)
			{}
				void tampilSimpul()
				{
					cout<<dData<<"	"<<nama<<"  "<<posisi;
				}
};
class SenaraiBerantai
{
	private:
		Simpul*pPertama;
		
	public:
		SenaraiBerantai() :pPertama(NULL)
		{}

	~SenaraiBerantai()
	{
		Simpul*pSkrg =pPertama;
		while(pSkrg!=NULL)
		{
			Simpul*pLama=pSkrg;
			pSkrg = pSkrg->pBrktnya;
			delete pLama;
		}
	}
		bool apaKosong()
		{ return(pPertama==NULL);}
		
			void sisipPertama(double dd, string n, string pos)
			{
				Simpul*pSimpulBaru=new Simpul(dd, n, pos);
				pSimpulBaru->pBrktnya=pPertama;
				pPertama=pSimpulBaru;
			}
			double hapusPertama()
			{
				Simpul*pTemp=pPertama;
				pPertama = pPertama->pBrktnya;
				double kunci=pTemp->dData;
				delete pTemp;
				return kunci;
			}
			void tampilSenarai()
			{
				Simpul*pSkrg=pPertama;
				while(pSkrg !=NULL)
				{
					pSkrg->tampilSimpul();
					pSkrg = pSkrg->pBrktnya;
				}
				cout<<endl;
			}
	};
	class TumpukanSenarai
	{
		private:
			SenaraiBerantai*pSenarai;
		public:
			TumpukanSenarai()
			{ pSenarai = new SenaraiBerantai; }
			~TumpukanSenarai()
			{ delete pSenarai; }
				void push(double j, string x, string z)
			{ pSenarai->sisipPertama (j, x, z); }
				
				double pop()
			{ return pSenarai->hapusPertama(); }
			
				bool apaKosong()
			{ return (pSenarai->apaKosong()); }
				void tampilTumpukan()
			{
				cout<<"Tumpukan (ata-->bawah):";
				pSenarai->tampilSenarai();
			}
	};
	
	int main()
	{
		TumpukanSenarai t;
		int pil;
		double nomor;
		string nm, ps;
		do{
		cout<<"-----------------------------------------------------------------------------------"<<endl;
		cout<<"                                    STACK                                               "<<endl<<endl<<endl;
		cout<<"1.PUSH "<<endl;
		cout<<"2.POP "<<endl;
		cout<<"3.TAMPIL "<<endl;
		cout<<"4.EXIT "<<endl;
		cout<<"PILIH :  ";
		cin>>pil;
		switch(pil)
		{
			case 1 : cout<<"No punggung : "; cin>>nomor;
					 cout<<"Nama : "; cin>>nm;
					 cout<<"Posisi : "; cin>>ps;
					
					t.push(nomor, nm, ps);
				break;
			case 2 : t.pop();
				break;
			case 3 : t.tampilTumpukan();
				break;
		}
			
	}while(pil!=4);
	return 0;
}

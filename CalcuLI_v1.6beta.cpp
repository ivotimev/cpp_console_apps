//Programa za reshavane na kvadratni uravneniq
//Izrabotena ot Ivo Timev
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
    cout<<"CalcuLI v1.6(beta)";
    cout<<"\n"<<char(251)<<char(201)<<char(205)<<char(187)<<endl<<" "<<char(200)<<char(205)<<char(188)<<endl;
    int YES=1;
    do
    {

        cout<<"\n\nPrograma za reshavane kvadratni uravneniq.\n"<<"ax^2+bx+c=0"<<endl<<"Za da polu4ite otgovor, molq\n";
        cout<<"vyvedete stoinost za a=";
        double a;
        cin>>a;
        cout<<"\nvyvedete stoinost za b=";
        double b;
        cin>>b;
        cout<<"\nvyvedete stoinost za c=";
        double c;
        cin>>c;
        cout<<"\nUravnenieto ("<<a<<")x^2+("<<b<<")x+("<<c<<")"<<"=0"<<endl;
        if(a==0)
        {
            if(b==0)
            {
                if(c==0)
                    cout<<"Vsqko X e reshenie.\n";
                else
                    cout<<"Nqma reshenie.\n";
            }
            else
            {
                double x;
                x=-c/b;
                if(floor(x)==x)
                    cout<<"X="<<x;
                else
                {
                    double y3=2,c9=c,b9=b;
                    while((y3<=abs(b9))||(y3<=abs(c9)))
                    {
                        if(floor(c/y3)==c/y3)
                        {
                            if(floor(b/y3)==b/y3)
                            {
                                c=c/y3;
                                b=b/y3;
                            }
                            else
                                y3=y3+1;
                        }
                        else
                            y3=y3+1;
                    }
                    cout<<"X=-"<<c<<"/"<<b<<endl;
                }
            }
        }
        else
        {
            double d;
            d=b*b-4*a*c;
            if(d>=0)
            {
                if(floor(sqrt(d))==sqrt(d))
                {
                    double x1;
                    x1=(-b+sqrt(d))/(2*a);
                    if(floor(x1)==x1)
                        cout<<"\nX1="<<x1<<endl;
                    else
                    {
                        double m,g=2*a,m9=m,g9=g;
                        m=-b+sqrt(d);
                        int y2=2;
                        while((y2<=abs(m9))||(y2<=abs(g9)))
                        {
                            if(floor(m/y2)==m/y2)
                            {
                                if(floor(g/y2)==g/y2)
                                {
                                    m=m/y2;
                                    g=g/y2;
                                }
                                else
                                    y2=y2+1;
                            }
                            else
                                y2=y2+1;
                        }
                        if(g!=0)
                            cout<<"\nX1="<<m<<"/"<<g<<endl;
                        else
                            cout<<"\nX1="<<m<<endl;
                    }
                    double x2;
                    x2=(-b-sqrt(d))/(2*a);
                    if(floor(x2)==x2)
                        cout<<"X2="<<x2<<endl;
                    else
                    {
                        double n,f=2*a,n9=n,f9=f;
                        n=-b-sqrt(d);
                        int y1=2;
                        while((y1<=abs(n9))||(y1<=abs(f9)))
                        {
                            if(floor(n/y1)==n/y1)
                            {
                                if(floor(f/y1)==f/y1)
                                {
                                    n=n/y1;
                                    f=f/y1;
                                }
                                else
                                    y1=y1+1;
                            }
                            else
                                y1=y1+1;
                        }
                        if(f!=1)
                            cout<<"X2="<<n<<"/"<<f<<endl;
                        else
                            cout<<"X2="<<n<<endl;
                    }
                }
                else
                {
                    int i=2,k,j=1;
                    double v=d;
                    do
                    {
                        if(floor(v/i)==v/i)
                        {
                            if(k==i)
                            {
                                k=1;
                                j=j*i*i;
                                v=v/i;
                            }
                            else
                            {
                                k=i;
                                v=v/i;
                            }
                        }
                        else
                        {
                            i=i+1;
                        }
                    }
                    while(i<d);

                    double sj=sqrt(j),b9=b;
                    double dj=d/j,sj9=sj;
                    double q=2*a;
                    double q9=q;
                    int y=2;
                    while(((y<=abs(q9))||(y<=abs(b9)))||(y<=abs(sj9)))
                    {
                        if(floor(abs(q/y))==abs(q/y))
                        {
                            if(floor(abs(b/y))==abs(b/y))
                            {
                                if(floor(abs(sj/y))==abs(sj/y))
                                {
                                    q=q/y;
                                    b=b/y;
                                    sj=sj/y;
                                }
                                else
                                    y=y+1;
                            }
                            else
                                y=y+1;
                        }
                        else
                            y=y+1;
                    }
                    if(q==1)
                    {
                        if(b!=0)
                        {
                            if(sj!=1)
                            {
                                cout<<"\nX1=-"<<b<<"+"<<sj<<char(251)<<dj<<endl;
                                cout<<"X2=-"<<b<<"-"<<sj<<char(251)<<dj<<endl;
                            }
                            else
                            {
                                cout<<"\nX1=-"<<b<<"+"<<char(251)<<dj<<endl;
                                cout<<"X2=-"<<b<<"-"<<char(251)<<dj<<endl;
                            }

                        }
                        else
                        {
                            if(sj!=1)
                            {
                                cout<<"\nX1=-"<<sj<<char(251)<<dj<<endl;
                                cout<<"X2=-"<<sj<<char(251)<<dj<<endl;
                            }
                            else
                            {
                                cout<<"\nX1=-"<<char(251)<<dj<<endl;
                                cout<<"X2=-"<<char(251)<<dj<<endl;
                            }
                        }
                    }
                    else
                    {
                        if(sj!=1)
                        {
                            cout<<"\nX1=-"<<b<<"+"<<sj<<char(251)<<"("<<dj<<")/"<<q<<endl;
                            cout<<"X2=-"<<b<<"-"<<sj<<char(251)<<"("<<dj<<")/"<<q<<endl;
                        }
                        else
                        {
                            cout<<"\nX1=-"<<b<<"+"<<char(251)<<"("<<dj<<")/"<<q<<endl;
                            cout<<"X2=-"<<b<<"-"<<char(251)<<"("<<dj<<")/"<<q<<endl;
                        }
                    }
                }
            }
            else
            {
                cout<<"\nNqma realni koreni"<<endl;
            }
        }
    }
    while(YES);
}

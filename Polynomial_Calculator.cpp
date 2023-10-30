#include <iostream>
#include <cmath>
using namespace std;

class polynomial{
public:
	   class term{
 public:
      int exponent;
      int coeficent;
	  term*next;	
	  term()
	  {
	  	
	  }
	  term(int coeficent,int exponent)
	  {
	  	this->exponent=exponent;
	  	this->coeficent=coeficent;
	  	next=NULL;
	  }
};
	
private:	
	term*head;
	int size;
public:
      polynomial()
	  {
	  	head=new term();
	  	head=NULL;
	  	size=0;
	  }	
	  
	  polynomial (const polynomial &l)
	  {
	  	 term *temp=l.head;
	  	 if (l.head == nullptr)
		   {
              return;
           }
        head = l.head;
        term*current = head;


       while (temp->next != nullptr)
		 {
           current->coeficent = temp->coeficent;
           current->exponent = temp->exponent;
           temp = temp->next;
           current=current->next;
         }
        current->next = nullptr;
    
	  	
	  }
       
      ~polynomial()
      {
      	cout<<"\n Destructor called\n";
      	term*temp=head;
      	while(temp->next!=nullptr)
      	{
      		temp=temp->next;
      		delete head;
      		head=temp;
		  }
      	
	  }
	  void input()
	  {
	  	cout<<"Enter the number of terms you want in polynomial\n";
	  	cin>>size;
	  	int a,b;
	  	for(int i=0;i<size;i++)
	  	{
	  		if(i==0)
	  		{
			  
	  		 cout<<"Enter the "<<i+1<<"st cofficent\n";
	  		 cin>>a;
	  		 cout<<"Enter the "<<i+1<<"st exponent\n";
	  		 cin>>b;
	  		 if(b<0)
	  		 {
	  		 	cout<<"You are not allowed to enter negative\n";
	  		 	cout<<"Enter the "<<i+1<<"st exponent again!\n";
	  		    cin>>b;
			 }
	  		 insert(a,b);
	  		 
	  	    }
	  	    
	  	    else if(i==1)
	  		{
			  
	  		 cout<<"Enter the "<<i+1<<"nd cofficent\n";
	  		 cin>>a;
	  		 cout<<"Enter the "<<i+1<<"nd exponent\n";
	  		 cin>>b;
			 if(b<0)
	  		 {
	  		 	cout<<"You are not allowed to enter negative\n";
	  		 	cout<<"Enter the "<<i+1<<"nd exponent again!\n";
	  		    cin>>b;
			 }   
	  		 insert(a,b);
	  		 
	  	    }
	  	    
	  	    else if(i==2)
	  		{
			  
	  		 cout<<"Enter the "<<i+1<<"rd cofficent\n";
	  		 cin>>a;
	  		 cout<<"Enter the "<<i+1<<"rd exponent\n";
	  		 cin>>b;
	  		 if(b<0)
	  		 {
	  		 	cout<<"You are not allowed to enter negative\n";
	  		 	cout<<"Enter the "<<i+1<<"rd exponent again!\n";
	  		    cin>>b;
			 }
	  		 insert(a,b);
	  		 
	  	    }
	  	    
	  	    else
	  	    {
	  	    	
	  		 cout<<"Enter the "<<i+1<<"th cofficent\n";
	  		 cin>>a;
	  		 cout<<"Enter the "<<i+1<<"th exponent\n";
	  		 cin>>b;
	  		 if(b<0)
	  		 {
	  		 	cout<<"You are not allowed to enter negative\n";
	  		 	cout<<"Enter the "<<i+1<<"th exponent again!\n";
	  		    cin>>b;
			 }
	  		 insert(a,b);
	  		 	
			}
		}
		    cout<<"\nYou entered the polynomial\n";
		    print();
		    cout<<"\nAfter sorting and simplification\n";
	  	    simplify();
	  	    print();
	  	    cout<<"\nAfter adding similar exponent polynomial terms\n";
	  	    adding();
	  	    print();
	  }
	   
	   void insert(int c,int e)
	   {
	   	
	   	 term*newterm=new term(c,e);
	   	 term*temp=head;
	   	 if(head==NULL)
	   	 {
	   	 	head=newterm;
	   	 	return;
		 }
		 else
		 {
		 	while(temp->next!=NULL)
		 	{
		 		temp=temp->next;
			}
		 	temp->next=newterm;
		 }
	   	 
	   }
	   
	   void adding()
	   {
	   	 term*temp=head;
	   	 term*temp1=head;
	   	 
	   	 while(temp!=NULL)
	   	 {
	   	 	temp1=temp->next;
	   	 	while(temp1!=NULL)
	   	 	{
	   	 		if(temp->exponent==temp1->exponent)
	   	 		{
	   	 			temp->coeficent+=temp1->coeficent;
	
				}
	   	 		temp1=temp1->next;
			}
			
	   	 	temp=temp->next;
		 }
		 
		 term*cur=head;
	   	 while(cur->next!=NULL)
	   	 {
	   	 	if(cur->exponent==cur->next->exponent)
	   	 	{
	   	 		term*next1=cur->next->next;
	   	 		term*todelete=cur->next;
	   	 		cur->next=next1;
	   	 		delete todelete;
			}
			else
			{
				cur=cur->next;
			}
		 }
	   	 
	   }
	   
	   void simplify()
	   {
	   	
	   	 term*temp=head;
         term*temp1=head; 	   	
	   	 int t1,t2;
	   	 while(temp!=NULL)
	   	 {
	   	 	temp1=temp->next;
	   	 	while(temp1!=NULL)
	   	 	{
	   	 	   if(temp1->exponent>temp->exponent)
				{
					t1=temp1->coeficent;
					t2=temp1->exponent;
					temp1->coeficent=temp->coeficent;
					temp1->exponent=temp->exponent;
					temp->coeficent=t1;
					temp->exponent=t2;
			    }	
	   	 		temp1=temp1->next;
			}
	   	 	temp=temp->next;
		 }
	   	
	   	
	   }
	   
	   polynomial const operator +(polynomial const &p)
	   {
	      polynomial l;
	   	  l.head=new term(0,0);
	   	  term*h1=this->head;
	   	  term*h2=p.head;
          term*temp=l.head;
          while(h1!=NULL && h2!=NULL)
          {
          	if(h1->exponent> h2->exponent)
          	{
          		temp->next=h1;
          		h1=h1->next;
			}
			else
			{
				temp->next=h2;
          		h2=h2->next;
			}
			temp=temp->next;
          	
		  }
	      

	      while(h1!=NULL)
	      {
	      	temp->next=h1;
          	h1=h1->next;
          	temp=temp->next;
		  }
		  
		  while(h2!=NULL)
	      {
	      	temp->next=h2;
          	h2=h2->next;
          	temp=temp->next;
		  }

         term*cur=l.head;
	   	 while(cur->next!=NULL)
	   	 {
	   	 	if(cur->exponent==cur->next->exponent)
	   	 	{
	   	 		cur->coeficent+=cur->next->coeficent;
	   	 		term*next1=cur->next->next;
	   	 		term*todelete=cur->next;
	   	 		cur->next=next1;
	   	 		delete todelete;
			}
			else
			{
				cur=cur->next;
			}
		 } 
		  l.head=l.head->next;
		  return l;
	   }
	   
	   
	   polynomial operator *(polynomial p)
	   {
	      polynomial l;
		  	
	   	  l.head=new term(0,0);
	   	  term*h1=this->head;
	   	  term*h2=p.head;
          term*temp=l.head;
          while(h1!=NULL && h2!=NULL)
          {
          	if(h1->exponent> h2->exponent)
          	{
          		temp->next=h1;
          		h1=h1->next;
			}
			else
			{
				temp->next=h2;
          		h2=h2->next;
			}
			temp=temp->next;
          	
		  }
	      
	      
	      while(h1!=NULL)
	      {
	      	temp->next=h1;
          	h1=h1->next;
          	temp=temp->next;
		  }
		  
		  while(h2!=NULL)
	      {
	      	temp->next=h2;
          	h2=h2->next;
          	temp=temp->next;
		  }

         term*cur=l.head;
	   	 while(cur->next!=NULL)
	   	 {
	   	 	if(cur->exponent==cur->next->exponent)
	   	 	{
	   	 		cur->coeficent*=cur->next->coeficent;
	   	 		term*next1=cur->next->next;
	   	 		term*todelete=cur->next;
	   	 		cur->next=next1;
	   	 		delete todelete;
			}
			else
			{
				cur=cur->next;
			}
		 } 
		  l.head=l.head->next;
		  return l;
	   }
	   
	   void print()
	   {
	   	
	   	 term*temp=head;
	   	 
	   	 if(temp->exponent!=0)
	   	 	{
	   	 		
	   	 	 cout<<temp->coeficent<<"n"<<temp->exponent<<" ";
				 	 
	   	    }
	   	    else
	   	    {
	   	    	cout<<temp->coeficent<<" ";
			}
         temp=temp->next;
  	   	 
	   	 while(temp!=NULL)
	   	 {
	   	 	if(temp->coeficent<0)
	   	 	{
				
	   	 	  if(temp->exponent!=0)
	   	 	   {
	   	 		
	   	 	     cout<<temp->coeficent<<"n"<<temp->exponent<<" ";
				 	 
	   	       }
	   	      else
	   	       {  
	   	    	 cout<<temp->coeficent<<" ";
		  	   }
			
			    temp=temp->next;
		    }
		    
		    else
		    {
		    	
		    	if(temp->exponent!=0)
	   	 	   {
	   	 		
	   	 	     cout<<"+"<<temp->coeficent<<"n"<<temp->exponent<<" ";
				 	 
	   	       }
	   	      else
	   	       {  
	   	    	 cout<<"+"<<temp->coeficent<<" ";
		  	   }
			
			    temp=temp->next;
		    	
			}
		    
	   	
	     }
       }
       
	  long evaluation(int a)
	  {
	  	
	  	long b=0;
	  	term*temp=head;
	  	while(temp!=NULL)
	  	{
	  		if(temp->exponent!=0)
	  		{
	  			int c=0;
	  			c=pow(a,temp->exponent);
	  			b+=temp->coeficent*c;
			}
			else
			{
				b+=temp->coeficent;
			}
	  		temp=temp->next;
		}
	  	  return b;
	  } 
	  
};
int main()
{
	polynomial l1,l2;
	l1.input();
	cout<<"\n\nHere is your second polynomial\n";
	l2.input();
	polynomial l3=l1+l2;
	cout<<"\n\nAfter overload + operator\n";
	l3.print();
	cout<<endl;
	cout<<"\n\n\npolynomial for multiplication\n";
	polynomial l4,l5,l6;
	l4.input();
	cout<<"\n\nHere is your second polynomial\n";
	l5.input();
	l6=l4*l5;
	cout<<"\nAfter overload * operator\n";
	l6.print();
	cout<<endl;
	int a;
	long b;
	cout<<"Enter the value of n: ";
	cin>>a;
	b=l6.evaluation(a);
	cout<<"\nAfter evaluation\n"<<b;
		
	return 0;
	system("pause");
}
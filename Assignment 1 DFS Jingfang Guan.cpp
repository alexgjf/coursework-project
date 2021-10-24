/*
 * Image Component Labeling
 * Project 1
 * Jingfang Guan
 * 2/25/2020
 *
 * Purpose and usage of this application
 *
 */
#include <string>
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

void getUserParams(int s, int d, int *size, int *density)
{
	char default_value;
	//default values are 10 for dimension, 0.4 for density.
	cout << "Welcome to the image Component Labeling program!"<<endl;
	cout << "The default value of deminsion is: "<<s ;
	cout << ", and the default value of density is: " << d << "%" <<endl;
	while (true)
	{
		cout << "Use default dimension and density? (y/n): ";
		cin >> default_value;
		if (default_value=='y'||default_value=='n')
		{
			break;
		}
	}
	// if no, get user's values
	if (default_value=='n')
	{
		do
		{
			cout << endl << "Please enter a dimension between 5 and 20: ";
			cin >> s;
		} while (s<5||s>20);
		do
		{
			cout << endl << "Please enter a dimension between 1 and 100: ";
			cin >> d;
		} while (d<=1||d>=100);
	}
	*size= s;
	*density=d;
}

main()
{
	int default_size = 10, default_density = 40;
	int size, density;
	getUserParams(default_size, default_density, &size, &density);
	//print value of dimension and density
	cout << endl << "Accepted Values:" << endl;
	cout << "Dimension: " << size << endl;
	cout << "Density: " << density << endl;

	cout << endl << "Grids successfully created!" << endl;
	int grid[size][size];
	int color[size][size];
	int R;
	//generate wall
	//for (int i = 0; i <= size+1; i++)
	for (int i = 0; i<=size+1; i++)
	{
		grid[0][i] = grid[size + 1][i] = 0; // bottom and top          
		grid[i][0] = grid[i][size + 1] = 0; // left and right
	}
	//generate grids
	for (int row = 1; row <=size;  row++)
	{
		for (int col = 1; col <=size;  col++)
		{
			R = rand() % 100;
			color[row][col]=0;
			if (R>density)
			{
				grid[row][col]=0;
			}
			else
			{
				grid[row][col]=1;
			}
			cout << "| "<<grid[row][col]<<", "<< color[row][col]<<" |";
		}
		cout << endl;
	}
	cout << endl;
	// scan all pixels labeling components
   	int id;  // component id
   	int label_no = 2, temp_label;
   	stack<int> x,y;
   	
   	//dfsgrid
   	for (int r = 1; r <= size; r++)      // row r of image
      	for (int c = 1; c <= size; c++)   // column c of image
	        if (grid[r][c] == 1)
	        {   
				id=1;  
	        	grid[r][c]=label_no;
				color[r][c]=id;     
				x.push(c);
				y.push(r);
				while(!x.empty()&&!y.empty()) 
				{
					if (grid[y.top()][x.top()+1]==1)
					{
						id++;
						grid[y.top()][x.top()+1]=label_no;
						color[y.top()][x.top()+1]=id;
						x.push(x.top()+1);
						y.push(y.top());
					} 
					else if (grid[y.top()+1][x.top()]==1)
					{
						id++;
						grid[y.top()+1][x.top()]=label_no;
						color[y.top()+1][x.top()]=id;
						x.push(x.top());
						y.push(y.top()+1);
					} 
					else if (grid[y.top()][x.top()-1]==1)
					{
						id++;
						grid[y.top()][x.top()-1]=label_no;
						color[y.top()][x.top()-1]=id;
						x.push(x.top()-1);
						y.push(y.top());
					} 
					else if (grid[y.top()-1][x.top()]==1)
					{
						id++;
						grid[y.top()-1][x.top()]=label_no;
						color[y.top()-1][x.top()]=id;
						x.push(x.top());
						y.push(y.top()-1);
					} 
					else
					{
						x.pop();
						y.pop();
					}
				}
				label_no++;
			}
	for (int row = 1; row <=size;  row++)
	{
		for (int col = 1; col <=size;  col++)
		{
			cout << "| "<<grid[row][col]<<", "<< color[row][col]<<" |";
		}
		cout<<endl;
	}
} 








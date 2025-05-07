#include <iostream>
#include <string>
using namespace std;

struct node // Node Declaration
{
    string label;
    int ch_count; // Number of chapters, sections, or subsections
    struct node *child[10]; // Child nodes (could be chapters, sections, or subsections)
} * root;

class GT // Class Declaration
{
public:
    void create_tree();
    void display(node *r1);
    void delete_tree(node *r1); // Function to deallocate memory

    GT()
    {
        root = NULL;
    }

    ~GT() {
        delete_tree(root);  // Destructor to free memory
    }
};

void GT::create_tree()
{
    int tchapters, tsections, tsubsections, i, j, k;
    root = new node;
    cout << "Enter name of book: ";
    cin.ignore();  // Ignore any leftover newline
    getline(cin, root->label);
    cout << "Enter number of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;
    
    // Loop through chapters
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter the name of Chapter " << i + 1 << ": ";
        cin.ignore();
        getline(cin, root->child[i]->label);
        cout << "Enter number of sections in Chapter " << root->child[i]->label << ": ";
        cin >> tsections;
        root->child[i]->ch_count = tsections;
        
        // Loop through sections of each chapter
        for (j = 0; j < tsections; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Name of Section " << j + 1 << ": ";
            cin.ignore();
            getline(cin, root->child[i]->child[j]->label);
            cout << "Enter number of subsections in Section " << root->child[i]->child[j]->label << ": ";
            cin >> tsubsections;
            root->child[i]->child[j]->ch_count = tsubsections;
            
            // Loop through subsections of each section
            for (k = 0; k < tsubsections; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "Enter Name of Subsection " << k + 1 << ": ";
                cin.ignore();
                getline(cin, root->child[i]->child[j]->child[k]->label);
            }
        }
    }
}

void GT::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy---";
        cout << "\nBook title: " << r1->label;
        tchapters = r1->ch_count;

        // Loop through chapters
        for (i = 0; i < tchapters; i++)
        {
            cout << "\nChapter " << i + 1 << ": " << r1->child[i]->label;
            cout << "\nSections: ";
            
            // Loop through sections
            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n  Section " << j + 1 << ": " << r1->child[i]->child[j]->label;
                cout << "\n  Subsections: ";
                
                // Loop through subsections
                for (k = 0; k < r1->child[i]->child[j]->ch_count; k++)
                {
                    cout << "\n    Subsection " << k + 1 << ": " << r1->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
    cout << endl;
}

void GT::delete_tree(node *r1) {
    if (r1 != NULL) {
        for (int i = 0; i < r1->ch_count; i++) {
            for (int j = 0; j < r1->child[i]->ch_count; j++) {
                for (int k = 0; k < r1->child[i]->child[j]->ch_count; k++) {
                    delete r1->child[i]->child[j]->child[k];  // Delete subsections
                }
                delete r1->child[i]->child[j];  // Delete sections
            }
            delete r1->child[i];  // Delete chapters
        }
        delete r1;  // Finally, delete the book node
    }
}

int main()
{
    int choice;
    GT gt;
    while (1)
    {
        cout << "-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;  // Added break
        case 2:
            gt.display(root);
            break;
        case 3:
            cout << "Thanks for using this program!!!" << endl;
            return 0;  // Changed to normal exit
        default:
            cout << "Wrong choice!!!" << endl;
        }
    }
    return 0;
}


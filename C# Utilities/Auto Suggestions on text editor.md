# Auto Suggestions on text box
©tomal tarek, arcola,sk

As you type in, when you press space key, a nice and cool auto-suggestions list will pop up based on previous word. 

```C#
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using AutocompleteMenuNS;
using System.Xml;
using System.Xml.Linq;

namespace AutoSuggestion
{
    public partial class Form1 : Form
    {
        XmlDocument doc = new XmlDocument();
        
        public Form1()
        {
            InitializeComponent();
            //have to put a 
            doc.Load("AutoSuggestions.xml");
        }

       
  // pressing shift key will produce autosuggestions based on previous word
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar ==32)   // shift key         
            {              
                contextMenuStrip1.Items.Clear();
                XmlNodeList xnList = doc.SelectNodes("/SuggestionList/BaseWord[@word=" + "'" + CurrentWord() + "']/Suggestion");
                if (xnList.Count > 0)
                {
                    foreach (XmlNode xn in xnList)
                    {
                        contextMenuStrip1.Items.Add(xn.InnerText);
                    }
                    contextMenuStrip1.Items.Add("্= Exit Menu");
                }
             
                contextMenuStrip1.Show(this.textBox1, new Point(this.textBox1.Left, 0));
                              
            }         

        }

        private void contextMenuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
              if (e.ClickedItem.Text!= "্= Exit Menu")
                textBox1.Paste(e.ClickedItem.Text);                  
          
          }

        private string CurrentWord()
        {
            int wordEndPosition = textBox1.SelectionStart;
            int currentPosition = wordEndPosition;

            while (currentPosition > 0 && textBox1.Text[currentPosition - 1] != ' ')
            {
                currentPosition--;
            }

            string word = textBox1.Text.Substring(currentPosition, wordEndPosition - currentPosition);
            return word;
        }

        
    }
}

```

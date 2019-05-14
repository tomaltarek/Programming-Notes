 
 
 ```C#
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
```

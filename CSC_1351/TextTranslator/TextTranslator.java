package TextTranslator;

//Student Name: Nathan Wandera
//LSU ID: 891973040

import java.util.TreeMap;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TextTranslator {
    
    public static void main(String[] args) throws FileNotFoundException
    {
        TreeMap<String, String> abbreviation = new TreeMap<>(String.CASE_INSENSITIVE_ORDER);
        File file = new File("acronyms.txt");
        Scanner scan = new Scanner(file);

        while(scan.hasNextLine()) // place all abbrevations and text counterpart into a treemap
        {

            String line = scan.nextLine();
            String[] acroynms = line.split("\t");
            
            abbreviation.put(acroynms[0], acroynms[1]);
          
        }
        scan.close();

        // read user input
        Scanner in = new Scanner(System.in).useDelimiter("\\n");
        String userInput = in.next();
        String[] words = userInput.split("\\s+"); 
        
        for(String word : words)
        {
            
            char punctuation = word.charAt(word.length() - 1);
            String newWord = word.replaceAll("\\p{Punct}", "");
            // check if the word ends with puncuation, and if the word without punctation is in the list of keys.
            if(Character.toString(punctuation).matches("\\p{Punct}") && abbreviation.get(newWord) != null) 
            {
               System.out.printf((abbreviation.get(newWord)).toLowerCase() + punctuation + " ");
            }
            else if(abbreviation.get(word) != null)
            {
                System.out.printf((abbreviation.get(word) + " ").toLowerCase());
            }
            else if(abbreviation.get(word) == null)
            {
                System.out.printf(word + " ");
            }
        }

        in.close();
    
    }

}

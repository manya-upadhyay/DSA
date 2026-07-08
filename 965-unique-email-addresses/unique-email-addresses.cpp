class Solution {
public:
    int numUniqueEmails(std::vector<std::string>& emails) {
        std::unordered_set<std::string> uniqueEmails;
        
        for (const std::string& email : emails) {
            std::string cleanedEmail = "";
            
            // Step 1: Process the local name
            for (size_t i = 0; i < email.length(); ++i) {
                if (email[i] == '.') {
                    continue; // Skip dots completely
                }
                if (email[i] == '+') {
                    // Skip everything until we hit the '@' sign
                    while (email[i] != '@') {
                        i++;
                    }
                }
                if (email[i] == '@') {
                    // Once we reach '@', append the rest of the string (domain name)
                    cleanedEmail += email.substr(i);
                    break; 
                }
                
                cleanedEmail += email[i];
            }
            
            // Step 2: Insert the fully processed email into our set
            uniqueEmails.insert(cleanedEmail);
        }
        
        return uniqueEmails.size();
    }
};
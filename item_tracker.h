#ifndef ITEM_TRACKER_H_
#define ITEM_TRACKER_H_

#include <map>
#include <string>

class ItemTracker {
public:
	//Google style recommends explicit for constructors to prevent implicit conversions.
	explicit ItemTracker() { loadData(); } //automatically loadData for default settings.
	void loadData(); // Reads the file stream data into the frequency map
	int getItemCount(const std::string& item) const; // Menu option 1
	void displayAllFrequencies() const; // Menu option 2
	void displayHistogram(char symbol = '*') const; // Menu option 3
	void writeBackup() const; // Write frequency map data to frequency.dat
	void setFileName(const std::string& file_name); //For changing the default file name.
private:
	// For tracking item and frequency pairing, initialized as an empty map.
	std::map<std::string, int> frequency_map_; 
	// Stores the input the constructor utilizes. Could set to default, or easily update to accept new file names.
	std::string input_file_name_ = "CS210_Project_Three_Input_File.txt"; //could just set this as the default file name as well here.
	std::string backup_file_name_ = "frequency.dat"; // Backup file name.
};
#endif

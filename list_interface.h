#ifndef list_interface_h
#define list_interface_h

template <typename T>
class ListInterface {
public:
    /*Check if the array if empty or not.
    @ return true if it is empty, otherwise return false.*/
    virtual bool isEmpty() const = 0;

    /*Insert the given data at the given position in the list.
    @ pre None
    @ post If the newPosition is in between 1 and numberOfItemInList + 1,
    the data will be set to the given newPosition,
    and other data after that will be renumbered.
    count will be increased by 1.
    If not, a message will be printed.
    @ param newPosition  The position that is wanted the data to be at.
    @ param data   The data that need to insert to the list.*/
    virtual void insertData(int newPosition, T &data) = 0;

    /*Remove the given data in the list.
    @ pre None
    @ post If the position is in between 1 and numberOfItemInList,
    the data in the given position will be removed,
    and other data after that will be renumberd.
    count will be decreased by 1.
    If not, a message will be printed.

    @ param position  the position that user want te remove the data at.*/
    virtual void removeData(int position) = 0;

    /*Get data at given position in the list.
    @ pre None
    @ post If the position is in between 1 and nummberOfItemInList,
    the data in the given posisiton will be found.
    If not, an exception will be thrown.

    @param position   the position that user want to get the data at.
    @return the data value.*/
    virtual T getData(int position) const = 0;

    /*Get the number of data in the list.
    @return the number of items in the list*/
    virtual int numberOfItemInList() const = 0;

    /*Remove all the data from the list.
    @ post The list will contain no data and count will become 0.*/
    virtual void emptyTheList() = 0;

    /*Print all the data from the list.
    @ pre None
    @ post There will be one pointer traverse through to list,
    and print every data inside the list.*/
    virtual void print() = 0;

    /*Replace the data at the given position with the newData in the list.
    @ pre None
    @ post If the position is in between 1 and numberOfItemInList,
    the data at the given position is newData.
    If not, a message will be printed.

    @ param position The position in the list of the data to replace.
    @ param newData The data that will replace the old data at the given position.
    */
    virtual void replaceItem(int position, T & newData) = 0;

    /*Search the given data in the list.
    @ pre None
    @ post If the given data exists in the list,
    return position of the data in the list.
    If not, return -1.

    @ param data  The value that is wanted to know if it exist in the list.
    @ return position in the list.
    */
    virtual int search(T &data) = 0;

    /*Add the data to the list.
    @ pre None
    @ post Add the data to the list.
    If the list contain no data, it will be added at the first position,
    otherwise, it will be added to the list depending on the sortType of the list.

    @ param data  The value tha is wanted to add into the list.
    */
    virtual void addData(T &data) = 0;
};

#endif /* list_interface_h */

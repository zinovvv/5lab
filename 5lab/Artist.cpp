#include "Artist.h"
#include <iostream>

Artist::Artist(const std::string& name, int numAlbums)
    : name(name), numAlbums(numAlbums) {}

Artist::Artist(const Artist& other) {
    name = other.name;
    numAlbums = other.numAlbums;
    albums = other.albums;
}

Artist::Artist() {};

void Artist::SetAlbums(const std::vector<Album>& newAlbums) {
    albums = newAlbums;
}

void Artist::PrintAlbums() const {
    for (const Album& album : albums) {
        album.OutputAlbum();
        std::cout << std::endl;
    }
}

void Artist::DeleteAlbum() {
    int number;
    while (true) {
        try{
            std::cout << "������� ����� �������, ������� ������ �������: " << std::endl;
            std::cin >> number;
            std::cin.ignore();
            if (number < 1 || number > albums.size()) {
                throw std::out_of_range("������������ ����� �������");
            }
            albums.erase(albums.begin() + number - 1);
            break;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "������ �������� �������: " << e.what() << std::endl;
        }
    }
}
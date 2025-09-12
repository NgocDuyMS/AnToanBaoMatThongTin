// noi dat logic ma hoa ceasar

package com.yourproject.service;

import org.springframework.stereotype.Service;

@Service
public class CaesarCipherService {

    public String encrypt(String text, int key) {
        StringBuilder result = new StringBuilder();
        for (char character : text.toCharArray()) {
            if (Character.isLetter(character)) {
                char base = Character.isLowerCase(character) ? 'a' : 'A';
                result.append((char) (((character - base + key) % 26) + base));
            } else {
                result.append(character);
            }
        }
        return result.toString();
    }
}
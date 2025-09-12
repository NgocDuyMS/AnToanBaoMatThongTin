// Lop nay dung de nhan du lieu tu Front_end , su dung Jackson lib de tu dong anh xa JSON
package com.yourproject.model;

public class EncryptionRequest {
    private String text;
    private int key;

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }
}
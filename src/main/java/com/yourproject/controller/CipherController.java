// lop nay xu ly cac yeu cau tu HTTP tu Front_End va goi Service de thuc hien ma hoa 

package com.yourproject.controller;

import com.yourproject.model.EncryptionRequest;
import com.yourproject.service.CaesarCipherService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/cipher")
public class CipherController {

    private final CaesarCipherService caesarCipherService;

    @Autowired
    public CipherController(CaesarCipherService caesarCipherService) {
        this.caesarCipherService = caesarCipherService;
    }

    @PostMapping("/encrypt-caesar")
    public String encryptCaesar(@RequestBody EncryptionRequest request) {
        // Gọi service để mã hóa và trả về kết quả
        return caesarCipherService.encrypt(request.getText(), request.getKey());
    }
}
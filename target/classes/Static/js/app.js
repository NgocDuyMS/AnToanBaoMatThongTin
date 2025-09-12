async function encrypt() {
    const text = document.getElementById('inputText').value;
    const key = document.getElementById('inputKey').value;

    const data = {
        text: text,
        key: parseInt(key, 10)
    };

    try {
        const response = await fetch('/api/cipher/encrypt-caesar', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(data)
        });

        if (!response.ok) {
            throw new Error(`HTTP error! status: ${response.status}`);
        }

        const result = await response.text(); // Lấy kết quả là text
        document.getElementById('resultText').innerText = result;
    } catch (error) {
        console.error('Error:', error);
        document.getElementById('resultText').innerText = "Có lỗi xảy ra!";
    }
}
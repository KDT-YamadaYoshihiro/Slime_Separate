#include "DxLib.h"

// =====================
// �~���N���b�N���ꂽ��
// =====================
inline bool CheckCircleClick(float circleX, float circleY, float radius) {

    // �}�E�X�̍��W���擾����
    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);

    // �N���b�N����
    if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) { // ���N���b�N�������ꂽ�ꍇ
        int distanceSquared = (mouseX - circleX) * (mouseX - circleX) + (mouseY - circleY) * (mouseY - circleY);
        if (distanceSquared <= radius * radius) {
            // �N���b�N���ꂽ�ꏊ���~�͈͓̔��ł����true��return����
            return true;
        }

    }
    return false;

}

// ========================
// �l�p���N���b�N���ꂽ�Ƃ�
// ========================
inline bool CheckBoxClick(float boxX, float boxY, float boxSizeX, float boxSizeY) {

    // �}�E�X�̍��W���擾����
    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);

    // �N���b�N����
    if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) { // ���N���b�N�������ꂽ�ꍇ

        if (mouseX >= boxX && mouseX <= boxX + boxSizeX &&
            mouseY >= boxY && mouseY <= boxY + boxSizeY)
        {
            // �N���b�N���ꂽ�ꏊ���l�p�͈͓̔��ł����true��return����
            return true;
        }
    }
    return false;

}

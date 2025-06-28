
import cv2
import numpy as np

image = cv2.imread("image.jpg")
cv2.imshow("original", image)
cv2.waitKey(0)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
cv2.imshow("blurred", blurred_image)
cv2.waitKey(0)

hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)
cv2.imshow("hsv", hsv_image)
cv2.waitKey(0)

hsv_min = np.array((36, 25, 25), np.uint8)
hsv_max = np.array((70, 255, 255), np.uint8)

green_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)

contours, hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
sorted_contur = sorted(contours, key=cv2.contourArea, reverse=True)

for i in sorted_contur:
    if cv2.contourArea(i) < 150:
        continue
    x, y, w, h, = cv2.boundingRect(i)
    cv2.circle(image, (x + w // 2, y + h // 2), 10, (0, 0, 255), 3)

cv2.imshow('contours', image)
cv2.waitKey(0)
cv2.destroyAllWindows()

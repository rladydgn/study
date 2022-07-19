from django.urls import reverse
from django.test import TestCase


class MyFirstTestCase(TestCase):
    def test_status(self):
        url = reverse("index")
        response = self.client.get(url)
        self.assertEquals(response.status_code, 200)

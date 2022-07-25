from django.shortcuts import render

# Create your views here.
from rest_framework.renderers import TemplateHTMLRenderer
from rest_framework.response import Response
from rest_framework.views import APIView


class RegisterAPIView(APIView):
    renderer_classes = [TemplateHTMLRenderer]
    template_name = "accounts/register.html"

    def get(self, request):
        return Response()

    def post(self, request):
        print("post called")
        return Response()

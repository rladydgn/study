from django.shortcuts import render
from rest_framework.decorators import api_view
from rest_framework.response import Response


# 데코레이터, GET 요청만 받는다.
@api_view(['GET'])
def testAPI(request):
    return Response("hello world")

from django.http import HttpResponse
from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt
from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.response import Response


# 데코레이터, GET 요청만 받는다.
from base.models import Book
from base.serializers import BookSerializer


@api_view(['GET'])
def testAPI(request):
    return Response("hello world")


# 데코레이터, csrf 토큰 검증 비활성화
@csrf_exempt
@api_view(['GET', 'POST'])
def ss(request):
    # GET 방식
    if request.method == 'GET':
        # db에 저장된 모든 Book 가져오기
        books = Book.objects.all()
        # data가 여러개 이므로 many=True
        serializer = BookSerializer(books, many=True)
        # data 반환
        return Response(serializer.data, status=status.HTTP_200_OK)
    # POST 방식
    elif request.method == 'POST':
        # 사용자에게 데이터 받아오기
        serializer = BookSerializer(data=request.data)
        # 유효한지 확인하기
        if serializer.is_valid():
            # 유효하면 저장, create() 메서드가 실행된다.
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

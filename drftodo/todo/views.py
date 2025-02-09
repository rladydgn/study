from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.generics import get_object_or_404
from rest_framework.response import Response

from todo.models import Todo
from todo.serializers import TodoSerializer, TodoDetailSerializer, TodoCreateSerializer


@api_view(['GET', 'POST'])
def todoListAPIView(request):
    # 리스트
    if request.method == 'GET':
        todos = Todo.objects.filter(complete=False)
        serializer = TodoSerializer(todos, many=True)
        return Response(serializer.data, status=status.HTTP_200_OK)

    # db 저장
    if request.method == 'POST':
        serializer = TodoCreateSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


@api_view(['GET', 'PUT'])
def todoRetrieveAPIView(request, pk):
    # 데이터 하나
    if request.method == 'GET':
        todo = get_object_or_404(Todo, id=pk)
        serializer = TodoDetailSerializer(todo)
        return Response(serializer.data, status=status.HTTP_200_OK)

    # 데이터 하나 수정
    if request.method == 'PUT':
        todo = get_object_or_404(Todo, id=pk)
        serializer = TodoCreateSerializer(todo, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_200_OK)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


# 완료한 todo list
@api_view(['GET'])
def completeTodoListAPIView(request):
    todo = Todo.objects.filter(complete=True)
    serializer = TodoSerializer(todo)
    return Response(serializer.data, status=status.HTTP_200_OK)
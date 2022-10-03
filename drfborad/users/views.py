from django.contrib.auth.models import User
from django.shortcuts import get_object_or_404
from rest_framework import status, generics
from rest_framework.response import Response
from rest_framework.views import APIView

from users.models import Profile
from users.permissions import CustomReadOnly
from users.serializers import RegisterSerializer, ProfileSerializer


class RegisterAPIView(APIView):

    def post(self, request):
        print(request.data)
        serializer = RegisterSerializer(data=request.data)
        if serializer.is_valid():
            # 시리얼라이저의 create가 실행되는 듯하다.
            # serializer의 save는 update를 할지 create를 할지 정해주는 역할만 한다.
            # 즉 실제 저장은 update, create 함수에서 이루어 진다.
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


class RegisterView(generics.CreateAPIView):
    queryset = User.objects.all()
    serializer_class = RegisterSerializer


class ProfileAPIView(APIView):
    permission_classes = [CustomReadOnly]
    def get(self, request, pk):
        print(pk)
        data = get_object_or_404(Profile, pk=pk)
        serializer = ProfileSerializer(data)
        return Response(serializer.data, status=status.HTTP_200_OK)

    def put(self, request, pk):
        data = get_object_or_404(Profile, pk=pk)
        serializer = ProfileSerializer(data, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_200_OK)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    
class ProfileView(generics.RetrieveUpdateAPIView):
    serializer_class = ProfileSerializer
    queryset = Profile.objects.all()
    permission_classes = [CustomReadOnly]

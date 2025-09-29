import fetcher from "../fetcher";
import useSWR from "swr";

function usePost(postId: string) {
  const {isLoading, data, error, mutate} = useSWR<MyNextApp.Post>(`/api/posts/${postId}`, fetcher)

  return {
    isLoading,
    post: data,
    error,
    mutate
  }
}

export default usePost;

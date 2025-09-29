import useSWR from "swr";
import fetcher from "../fetcher";

export default function usePosts() {
    const {isLoading, error, data, mutate} = useSWR<MyNextApp.Post[]>('/api/posts', fetcher);

    return {
        isLoading,
        posts: data,
        mutate,
        error
    }
}

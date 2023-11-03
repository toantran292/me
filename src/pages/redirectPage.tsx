import { useEffect } from 'react';
import { useParams } from 'react-router-dom';
import ErrorPage from './errorPage';
const DATA = {
    "google-dstt": "https://drive.google.com/drive/u/0/folders/10DwxI2J3PTWY7WJHc60vB0qvyYoh3sfI",
}

const RedirectPage = () => {
    const { redirectId } = useParams();
    console.log(redirectId)

    useEffect(() => {
        // Neu khong ton tai link thi cut
        const url = DATA[redirectId as keyof typeof DATA];
        if (!url) return;
        window.location.href = url;
    }, [])
    return <ErrorPage />
}

export default RedirectPage
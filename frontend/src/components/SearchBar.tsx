import { useState } from "react";

interface SearchBarProps {
  city: string;
  setCity: (city: string) => void;
  onSearch: () => void;
  suggestions: string[] | null;
  onSelectSuggestion: (city: string) => void;
}

function SearchBar({
  city,
  setCity,
  onSearch,
  suggestions,
  onSelectSuggestion,
}: SearchBarProps) {
  const [showSuggestions, setShowSuggestions] = useState(false);

  return (
    <div className="relative flex gap-3">
      <input
        className="
    rounded-full
    px-5
    py-3
    bg-white/10
    backdrop-blur-md
    border
    border-white/20
    text-white
    outline-none
  "
        value={city}
        onChange={(e) => {
          setCity(e.target.value);
          setShowSuggestions(true);
        }}
        onKeyDown={(e) => {
          if (e.key === "Enter") {
            setShowSuggestions(false);
            onSearch();
          }

          if (e.key === "Escape") {
            setShowSuggestions(false);
          }
        }}
        placeholder="Search city..."
      />
      <button
        className="
          rounded-full
          px-6
          bg-gray-500
          text-white
          hover:bg-black
          transition
          duration-300
          ease-in-out
          hover:scale-105
        "
        onClick={() => {
          setShowSuggestions(false);
          onSearch();
        }}
      >
        Search
      </button>

      {showSuggestions && suggestions?.length > 0 && (
        <div
          className="
            absolute
            top-14
            left-0
            w-full
            bg-black/70
            backdrop-blur-lg
            border
            border-white/20
            rounded-2xl
            overflow-hidden
            shadow-xl
            z-10
          "
        >
          {suggestions.map((suggestion, index) => (
            <button
              key={`${suggestion}-${index}`}
              className="
      block
      w-full
      text-left
      px-5
      py-3
      text-white
      hover:bg-white/20
      transition
    "
              onClick={() => {
                setShowSuggestions(false);
                onSelectSuggestion(suggestion);
              }}
            >
              {suggestion}
            </button>
          ))}{" "}
        </div>
      )}
    </div>
  );
}

export default SearchBar;
